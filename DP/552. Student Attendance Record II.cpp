//Nice Question
//Method - 1
class Solution {
public:
    #define ll long long
    int checkRecord(int n) {
        
        int mod = 1e9 + 7;
        
        ll dp[6][n + 1];
        memset(dp, 0, sizeof(dp));
        
        if(n == 1){
            return 3;
        }
                        //(Total, consecutive)
        dp[0][1] = 1;   //(A = 0 L = 0) 
        dp[1][1] = 1;   //(A = 0 L = 1) 'L' at last
        dp[2][1] = 0;   //(A = 0 L = 2) "LL" at last
        dp[3][1] = 1;   //(A = 1 L = 0) 'A' or 'P' at last
        dp[4][1] = 0;   //(A = 1 L = 1) 'L' at last
        dp[5][1] = 0;   //(A = 1 L = 2) "LL" at last
        
        for(int i = 2; i <= n; i++){
            
            dp[0][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1])%mod;
            
            dp[1][i] = (dp[0][i-1])%mod;
            
            dp[2][i] = (dp[1][i-1])%mod;
            
            dp[3][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1] + dp[3][i-1] + dp[4][i-1] + dp[5][i-1])%mod;
            
            dp[4][i] = (dp[3][i-1])%mod;
            
            dp[5][i] = (dp[4][i-1])%mod;
        }
        
        ll sum = 0;
        for(int i = 0; i < 6; i++){
            sum = (sum + dp[i][n])%mod;
        }
        return sum%mod;
    }
};

//Method - 2
class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int checkRecord(int n) {
        
        ll dp[n + 1][6];
        
        dp[1][0] = dp[1][1] = dp[1][5] = 1;
        dp[1][2] = dp[1][3] = dp[1][4] = 0;
        
        ll pre = 3;
        
        for(int i = 2; i <= n; i++){
            
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % mod;
            
            dp[i][1] = dp[i - 1][5] % mod;
                
            dp[i][2] = dp[i - 1][0] % mod;
                
            dp[i][3] = dp[i - 1][1] % mod;
                
            dp[i][4] = dp[i - 1][2] % mod;
                
            dp[i][5] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % mod;   
        }
        ll ans = 0;
        for(ll j = 0; j < 6; j++){
            ans = (ans + dp[n][j]) % mod;
        }
        return ans;
    }
};
