//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
//Similar to Longest Palindromic Substring
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
