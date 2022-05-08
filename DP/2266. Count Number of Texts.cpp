class Solution {
public:
    #define mod 1000000007
    #define ll long long
    int countTexts(string s) {
        
        unordered_map<string,char> umap;
        
        ll n = s.size();
        vector<ll> dp(n,0);
        
        dp[0] = 1;
        for(ll i = 1; i < n; i++){
            dp[i] = dp[i - 1];
            
            if(s[i] == s[i - 1]){
                if(i - 2 >= 0){
                    dp[i] = (dp[i] + dp[i - 2])%mod;
                }
                else{
                    dp[i] = (dp[i] + 1)%mod;
                }
            }
            else{
                continue;
            }
            if(i - 2 >= 0){
                if(s[i] == s[i - 2]){
                    if(i - 3 >= 0){
                        dp[i] = (dp[i] + dp[i - 3])%mod;
                    }
                    else{
                        dp[i] = (dp[i] + 1)%mod;
                    }
                }
                else{
                    continue;
                }
            }
            if((s[i] == '7' || s[i] == '9') && (i - 3 >= 0) && (s[i] == s[i - 3])){
                if(i - 4 >= 0){
                    dp[i] = (dp[i] + dp[i - 4])%mod;
                }
                else{
                    dp[i] = (dp[i] + 1)%mod;
                }
            }
        }
        return dp[n - 1]%mod;
    }
};
