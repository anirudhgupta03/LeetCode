class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string p;
        for(int i = s.size() - 1; i >=0 ; i--){
            p.push_back(s[i]);
        }
        
        int m = s.size(), n = p.size();
        
        int dp[m+1][n+1];
        
        for(int i = 0; i < m + 1; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j < n + 1; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                
                if(s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};
