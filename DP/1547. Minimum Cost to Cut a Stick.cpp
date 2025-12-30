//Top-Down
//TC: O(n*n*n)
//SC: O(n*n) + Auxilliary Stack Space
class Solution {
public:
    int findMinCost(int l, int r, vector<int> &tcuts, vector<vector<int>> &dp){
        if(l > r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        
        int minCost = INT_MAX;
        for(int k = l; k <= r; k++){
            int p1 = findMinCost(l, k - 1, tcuts, dp);
            int p2 = findMinCost(k + 1, r, tcuts, dp);
            if(p1 != INT_MAX && p2 != INT_MAX){
                minCost = min(minCost, tcuts[r + 1] - tcuts[l - 1] + p1 + p2);
            }
        }
        return dp[l][r] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int> tcuts = cuts;
        tcuts.push_back(0);
        tcuts.push_back(n);
        sort(tcuts.begin(), tcuts.end());
        
        int len = tcuts.size();
        vector<vector<int>> dp(len, vector<int>(len, -1));
        return findMinCost(1, tcuts.size() - 2, tcuts, dp);
    }
};

//Bottom-Up
//TC: O(n*n*n)
//SC: O(n*n)
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        vector<int> tcuts = cuts;
        tcuts.push_back(0);
        tcuts.push_back(n);
        sort(tcuts.begin(), tcuts.end());

        int len = tcuts.size();

        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for(int l = len - 2; l >= 1; l--){
            for(int r = l; r <= len - 2; r++){
                int minCost = INT_MAX;
                for(int k = l; k <= r; k++){
                    minCost = min(minCost, tcuts[r + 1] - tcuts[l - 1] + dp[l][k - 1] + dp[k + 1][r]);
                }
                dp[l][r] = minCost;
            }
        }
        return dp[1][len - 2];
    }
};
