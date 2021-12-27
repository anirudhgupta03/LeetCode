//Ref: https://www.youtube.com/watch?v=GPePWKCEy24
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int len1 = s1.size(), len2 = s2.size();
        
        int dp[len1 + 1][len2 + 1];
        
        dp[0][0] = 0;
        
        for(int j = 1; j <= len2; j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];    
        }
        
        for(int i = 1; i <= len1; i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j] + s1[i-1],dp[i][j-1] + s2[j-1]);
                }
            }
        }
        
        return dp[len1][len2];
    }
};
