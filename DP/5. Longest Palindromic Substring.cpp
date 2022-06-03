class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.size();
        
        bool dp[len][len];
        
        memset(dp,false,sizeof(dp));
        
        int maxlen = 1, start = 0;
        
        for(int i = 0; i < len; i++){
            dp[i][i] = true;
        }
        
        for(int i = 0; i < len - 1; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                if(maxlen == 1){
                    maxlen = 2;
                    start = i;
                }
            }
        }
        
        for(int i = len - 3; i >= 0; i--){
            for(int j = len - 1; j >= i + 2; j--){
                if(s[i] == s[j] && dp[i + 1][j - 1]){
                    dp[i][j] = true;
                    if(j - i + 1 >= maxlen){
                        maxlen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
