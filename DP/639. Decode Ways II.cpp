//Method - 1
class Solution {
public:
    #define ll long long
    int numDecodings(string s) {
        
        int len = s.size();
        
        if(s[0] == '0'){
            return 0;
        }
        
        int mod = 1e9 + 7;
        
        ll dp[len];
        memset(dp,0,sizeof(dp));
        
        if(s[0] == '*'){
            dp[0] = 9;
        }
        else{
            dp[0] = 1;
        }
        
        for(int i = 1; i < len; i++){
            
            if(s[i] == '0'){
                if(s[i-1] == '*'){
                    if(i - 2 >= 0) dp[i] = (dp[i-2]*2)%mod;
                    else           dp[i] = 2;
                }
                else if(s[i-1] == '0'){
                    return 0;
                }
                else{
                    if(s[i-1] == '1' || s[i-1] == '2'){
                        if(i - 2 >= 0) dp[i] = (dp[i-2])%mod;
                        else           dp[i] = 1;
                    }
                    else{
                        return 0;
                    }
                }
            }
            else if(s[i] == '*'){
                if(s[i-1] == '0'){
                    dp[i] = (9*dp[i-1])%mod;
                }
                else if(s[i-1] == '*'){
                    dp[i] = (dp[i-1]*9)%mod;
                    if(i - 2 >= 0) dp[i] = (dp[i] + dp[i-2]*15)%mod;
                    else           dp[i] = (dp[i] + 15)%mod;
                }
                else{
                    dp[i] = (9*dp[i-1])%mod;
                    if(s[i - 1] == '1'){
                        if(i - 2 >= 0) dp[i] = (dp[i] + dp[i-2]*9)%mod;
                        else           dp[i] = (dp[i] + 9)%mod;
                    }
                    if(s[i-1] == '2'){
                        if(i - 2 >= 0) dp[i] = (dp[i] + dp[i-2]*6)%mod;
                        else           dp[i] = (dp[i] + 6)%mod;
                    }
                }
            }
            else{
                if(s[i-1] == '0'){
                    dp[i] = dp[i-1];
                }
                else if(s[i-1] == '*'){
                    dp[i] = dp[i-1];
                    if(s[i] >= '1' && s[i] <= '6'){
                        if(i - 2 >= 0) dp[i] = (dp[i] + dp[i-2]*2)%mod;
                        else           dp[i] = (dp[i] + 2)%mod;
                    }
                    if(s[i] >= '7' && s[i] <= '9'){
                        if(i - 2 >= 0) dp[i] = (dp[i] + dp[i-2])%mod;
                        else           dp[i] = (dp[i] + 1)%mod;
                    }
                }
                else{
                    dp[i] = dp[i-1];
                    if(s[i-1] == '1'){
                        if(i - 2 >= 0) dp[i] = (dp[i] + dp[i-2])%mod;
                        else           dp[i] = (dp[i] + 1)%mod;
                    }
                    if(s[i-1] == '2' && (s[i] >= '1' && s[i] <= '6')){
                        if(i - 2 >= 0) dp[i] = (dp[i] + dp[i-2])%mod;
                        else           dp[i] = (dp[i] + 1)%mod;
                    }
                }
            }
        }
        return dp[len-1];
    }
};

//Method - 2
//Short & Concise Code
class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int numDecodings(string s) {
        
        int n = s.size();
        
        if(s[0] == '0'){
            return 0;
        }
        
        ll dp[n];
        
        dp[0] = s[0] == '*' ? 9 : 1;
        
        for(int i = 1; i < n; i++){
            
            if(s[i] == '*'){
                dp[i] = (9*dp[i - 1]) % mod ;
                if(s[i - 1] == '*'){
                    dp[i] = (dp[i] + ((i - 2) >= 0 ? 15*dp[i - 2] : 15)) % mod;
                }
                else if(s[i - 1] != '0'){
                    if(s[i - 1] == '1'){
                        dp[i] = (dp[i] + ((i - 2) >= 0 ? 9*dp[i - 2] : 9)) % mod;
                    }
                    else if(s[i - 1] == '2'){
                        dp[i] = (dp[i] + ((i - 2) >= 0 ? 6*dp[i - 2] : 6)) % mod;
                    }
                }
            }
            else if(s[i] == '0'){
                if(s[i - 1] == '*'){
                    dp[i] = ((i - 2) >= 0 ? 2*dp[i - 2] : 2) % mod;
                }
                else if(s[i - 1] == '0'){
                    dp[i] = 0;
                }
                else{
                    if(s[i - 1] == '1' || s[i - 1] == '2'){
                        dp[i] = ((i - 2) >= 0 ? dp[i - 2] : 1) % mod;
                    }
                    else{
                        dp[i] = 0;
                    }
                }
            }
            else{
                dp[i] = dp[i - 1] % mod;
                if(s[i - 1] == '*'){
                    if(s[i] <= '6'){
                        dp[i] = (dp[i] + ((i - 2) >= 0 ? 2*dp[i - 2] : 2)) % mod;
                    }
                    else{
                        dp[i] = (dp[i] + ((i - 2) >= 0 ? dp[i - 2] : 1)) % mod;
                    }
                }
                else if(s[i - 1] != '0'){
                    int val = stoi(s.substr(i - 1,2));
                    if(val >= 11 && val <= 26){
                        dp[i] = (dp[i] + ((i - 2) >= 0 ? dp[i - 2] : 1)) % mod;
                    }
                }
            }
        }
        return dp[n - 1] % mod;
    }
};
