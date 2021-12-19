//Ref: https://www.youtube.com/watch?v=-RDzMJ33nx8
class Solution {
public:
    int numDistinct(string s, string t) {
        
        int len1 = s.size(), len2 = t.size();
        
        double dp[len1 + 1][len2 + 1];
        
        for(int j = 0; j <= len2; j++){
            dp[0][j] = 0;
        }
        for(int i = 0; i <= len1; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[len1][len2];
    }
};
