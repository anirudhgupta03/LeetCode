class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.size(), m = p.size();
        
        int dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    if(p[j-1] == '*'){
                        dp[i][j] = dp[i][j-1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else if(j == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(p[j-1] == '*'){
                        dp[i][j] = dp[i][j-1] || dp[i-1][j];      //Imp Step
                    }
                    else if(p[j-1] == '?' || s[i-1] == p[j-1]){
                        dp[i][j] = dp[i-1][j-1]; 
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};
