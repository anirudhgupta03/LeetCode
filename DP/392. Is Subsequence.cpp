class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.size() > t.size()){
            return false;
        }
        
        int len1 = s.size(), len2 = t.size();
        
        int dp[len1 + 1][len2 + 1];
        
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        if(dp[len1][len2] == len1){
            return true;
        }
        return false;
    }
};
