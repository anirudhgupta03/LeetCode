//TC: O(n*n*n)
//SC: O(n*n) + Auxilliary Stack Space
class Solution {
public:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int mini = INT_MAX;
        
        for(int ind = i; ind <= j; ind++){
            int cost = cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts, dp) + solve(ind + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        n = cuts.size();
        vector<vector<int>> dp(n, vector<int>(n, - 1));
        return solve(1, n - 2, cuts, dp);
    }
};
