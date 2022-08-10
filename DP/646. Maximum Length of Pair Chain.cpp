//DP
//TC: O(n*n)
//SC: O(n)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end());
        
        int n = pairs.size();
        
        vector<int> dp(n, 1);
        int ans = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//Greedy
//TC: O(nlogn)
//SC: O(1)
class Solution {
public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        int e = pairs[0][1];
        
        int count = 1;
        
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] > e){
                e = pairs[i][1];
                count++;
            }
        }
        return count;
    }
};
