class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        
        if(s[0] == '0'){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        
        int dp[n];
        
        dp[0] = 1;
        
        for(int i = 1; i < n; i++){
            
            if(s[i-1] == '0' && s[i] == '0'){
               dp[i] = 0; 
            }
            else if(s[i-1] != '0' && s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2'){
                    if(i >= 2)
                    dp[i] = dp[i-2];
                    else
                    dp[i] = 1;
                }
                else{
                    dp[i] = 0;
                }
            }
            else if(s[i-1] == '0' && s[i] != '0'){
                dp[i] = dp[i-1];
            }
            else if(s[i-1] != '0' && s[i] != '0'){
                dp[i] = dp[i-1];
                
                int t = stoi(s.substr(i-1,2));
                
                if(t >= 1 && t <= 26){
                    if(i >= 2)
                    dp[i] += dp[i-2];
                    else
                    dp[i] += 1;
                }
            }
        }
        
        return dp[n-1];
    }
};
