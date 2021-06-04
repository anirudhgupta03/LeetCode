//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        
        int start = 0;
        int max_len = 1;
        
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                max_len = 2;
            }
            else{
                dp[i][i+1] = false;
            }
        }
        
        for(int k = 3; k <= n; k++){
            
            for(int i = 0; i <= n - k; i++){
                
                int j = i + k - 1;
                
                if((s[i] == s[j]) && (dp[i+1][j-1] == true)){
                    
                    dp[i][j] = true;
                    
                    if(k > max_len){
                        start = i;
                        max_len = k;
                    }
                }
            }
        }
        
        return s.substr(start,max_len);
    }
};
