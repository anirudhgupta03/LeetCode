class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int l1 = text1.length();
        int l2 = text2.length();
        
        int dp[l1+1][l2+1];
        
        for(int i = 0; i < l1 + 1; i++){
            for(int j = 0; j < l2 + 1; j++){
                dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < l1 + 1; i++){
            for(int j = 1; j < l2 + 1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[l1][l2];
    }
};
