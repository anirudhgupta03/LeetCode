class Solution {
public:
    int solve(int ind, int pre, int k, string &s, vector<vector<int>> &dp){
        
        if(ind == s.size()){
            return 0;
        }
        
        if(dp[ind][pre - 'a'] != -1){
            return dp[ind][pre - 'a'];
        }
        
        int maxLen = 0;
        
        if(pre == 123 || abs(pre - s[ind]) <= k){
            maxLen = max(maxLen, solve(ind + 1, s[ind], k, s, dp) + 1);
        }
        maxLen = max(maxLen, solve(ind + 1, pre, k, s, dp));
        return dp[ind][pre - 'a'] = maxLen;
    }
    int longestIdealString(string s, int k) {
        
        int len = s.size();
        
        vector<vector<int>> dp(len, vector<int>(27, -1));
        
        return solve(0, 123, k, s, dp);
    }
};
