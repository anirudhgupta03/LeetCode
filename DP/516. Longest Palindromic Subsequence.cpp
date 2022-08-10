//Top-Down
//TC: O(len*len)
//SC: O(len*len) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind1, int ind2, string &s, string &p, vector<vector<int>> &dp){
        
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        
        int maxLen = 0;
        if(s[ind1 - 1] == p[ind2 - 1]){
            maxLen = solve(ind1 - 1, ind2 - 1, s, p, dp) + 1;
        }
        else{
            maxLen = max(solve(ind1 - 1, ind2, s, p, dp), solve(ind1, ind2 - 1, s, p, dp));
        }
        return dp[ind1][ind2] = maxLen;
    }
    int longestPalindromeSubseq(string s) {
        
        int len = s.size();
        string p = s;
        reverse(p.begin(), p.end());
        
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s.size(), p.size(), s, p, dp);
    }
};

//Bottom-Up
//TC: O(len*len)
//SC: O(len*len)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int len = s.size();
        string p = s;
        reverse(p.begin(), p.end());
        
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1));
    
        for(int i = 0; i <= len; i++){
            for(int j = 0; j <= len; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s[i - 1] == p[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len][len];
    }
};

//Bottom-Up
//TC: O(len*len)
//SC: O(len)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int len = s.size();
        string p = s;
        reverse(p.begin(), p.end());
        
        vector<int> pre(len + 1, 0), curr(len + 1);
        
        for(int i = 1; i <= len; i++){
            for(int j = 0; j <= len; j++){
                if(i == 0 || j == 0){
                    curr[j] = 0;
                }
                else if(s[i - 1] == p[j - 1]){
                    curr[j] = pre[j - 1] + 1;
                }
                else{
                    curr[j] = max(pre[j], curr[j - 1]);
                }
            }
            pre = curr;
        }
        return pre[len];
    }
};
