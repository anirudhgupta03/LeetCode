class Solution {
public:
    int minInsertions(string s) {
        
        string p = s;
        reverse(p.begin(), p.end());
        
        int len = s.size();
        
        int dp[len + 1][len + 1];
        
        for(int i = 0; i <= len; i++){
            for(int j = 0; j <= len; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s[i - 1] == p[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return len - dp[len][len];
    }
};
