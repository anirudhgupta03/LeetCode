//Method - 1
class Solution {
public:
    int countSubstrings(string s) {
        
        int len = s.size();
        
        int dp[len][len];
        
        memset(dp,0,sizeof(dp));
        
        int count = 0;
        
        for(int i = 0; i < len; i++){
            count++;
            dp[i][i] = 1;
        }
        
        for(int i = 0; i < len - 1; i++){
            if(s[i] == s[i+1]){
                count++;
                dp[i][i+1] = 1;
            }
        }
        
        for(int k = 3; k <= len; k++){
            
            for(int i = 0; i <= len - k; i++){
                
                int j = i + k - 1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
        
        return count;
    }
};

//Method - 2
class Solution {
public:
    int countSubstrings(string s) {
        
        int len = s.size();
        
        bool dp[len][len];
        memset(dp, false, sizeof(dp));
        
        int count = 0;
        
        for(int i = 0; i < len; i++){
            dp[i][i] = true;
            count++;
        }
        
        for(int i = 0; i < len - 1; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                count++;
            }
        }
        
        for(int i = len - 3; i >= 0; i--){
            for(int j = len - 1; j >= i + 2; j--){
                if(s[i] == s[j] && dp[i + 1][j - 1]){
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
