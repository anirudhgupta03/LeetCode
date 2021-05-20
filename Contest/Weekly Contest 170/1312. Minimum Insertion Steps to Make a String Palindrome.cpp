class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
        string p = s;
        reverse(p.begin(),p.end());
        
        string dp[n+1][n+1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = "";
                }
                else if(s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1] + s[i-1];
                }
                else{
                    if(dp[i-1][j].size() > dp[i][j-1].size()){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return n - dp[n][n].size();
    }
};
