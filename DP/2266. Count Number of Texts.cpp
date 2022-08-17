//Method - 1
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

//Method - 2
class Solution {
public:
    #define ll long 
    #define mod 1000000007
    int countTexts(string pressedKeys) {
        
        unordered_map<string,char> umap;
        
        umap["2"] = 'a';
        umap["22"] = 'b';
        umap["222"] = 'c';
        umap["3"] = 'd';
        umap["33"] = 'e';
        umap["333"] = 'f';
        umap["4"] = 'g';
        umap["44"] = 'h';
        umap["444"] = 'i';
        umap["5"] = 'j';
        umap["55"] = 'k';
        umap["555"] = 'l';
        umap["6"] = 'm';
        umap["66"] = 'n';
        umap["666"] = 'o';
        umap["7"] = 'p';
        umap["77"] = 'q';
        umap["777"] = 'r';
        umap["7777"] = 's';
        umap["8"] = 't';
        umap["88"] = 'u';
        umap["888"] = 'v';
        umap["9"] = 'w';
        umap["99"] = 'x';
        umap["999"] = 'y';
        umap["9999"] = 'z';
        
        int n = pressedKeys.size();
        
        vector<ll> dp(n);
        
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = dp[i - 1];
            for(int j = i - 1; j >= 0; j--){
                if(umap.find(pressedKeys.substr(j, i - j + 1)) != umap.end()){
                    if(j == 0) dp[i] = (dp[i] + 1)%mod;
                    else dp[i] = (dp[i] + dp[j - 1])%mod;
                }
                else{
                    break;
                }
            }
        }
        return dp[n - 1] % mod;
    }
};
