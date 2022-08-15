//Top-Down
//TC: O(n*3)
//SC: O(n*3) + Auxilliary Stack Space
class Solution {
public:
    #define ll long long
    #define mod 1000000007
    ll solve(int ind, int count, int n, string &corridor, vector<vector<ll>> &dp){
        
        if(ind == corridor.size() && count == 2){
            return 1;
        }
        if(ind == corridor.size()){
            return 0;
        }
        
        if(dp[ind][count] != -1){
            return dp[ind][count];
        }
        ll ways = 0;
        
        if(count == 0){
            if(corridor[ind] == 'S'){
                ways = (ways + solve(ind + 1, 1, n, corridor, dp))%mod;
            }
            else{
                ways = (ways + solve(ind + 1, 0, n, corridor, dp))%mod;
            }
        }
        if(count == 1){
            if(corridor[ind] == 'S'){
                ways = (ways + solve(ind + 1, 2, n, corridor, dp))%mod;
            }
            else{
                ways = (ways + solve(ind + 1, 1, n, corridor, dp))%mod;
            }
        }
        if(count == 2){
            if(corridor[ind] == 'S'){
                ways = (ways + solve(ind + 1, 1, n, corridor, dp))%mod;
            }
            else{
                ways = (ways + solve(ind + 1, 2, n, corridor, dp) + solve(ind + 1, 0, n, corridor, dp))%mod;
            }
        }
        return dp[ind][count] = ways;
    }
    int numberOfWays(string corridor) {
        
        int n = corridor.size();
        vector<vector<ll>> dp(n, vector<ll>(3, -1));
        return solve(0, 0, n, corridor, dp);
    }
};

//Bottom-Up
//TC: O(n*3)
//SC: O(n*3)
class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int numberOfWays(string corridor) {
        
        int n = corridor.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(3));
        
        for(int ind = n; ind >= 0; ind--){
            for(int count = 2; count >= 0; count--){
                if(ind == n && count == 2){
                    dp[ind][count] =  1;
                }
                else if(ind == n){
                    dp[ind][count] = 0;
                }
                else{
                    ll ways = 0;

                    if(count == 0){
                        if(corridor[ind] == 'S'){
                            ways = (ways + dp[ind + 1][1])%mod;
                        }
                        else{
                            ways = (ways + dp[ind + 1][0])%mod;
                        }
                    }
                    else if(count == 1){
                        if(corridor[ind] == 'S'){
                            ways = (ways + dp[ind + 1][2])%mod;
                        }
                        else{
                            ways = (ways + dp[ind + 1][1])%mod;
                        }
                    }
                    else if(count == 2){
                        if(corridor[ind] == 'S'){
                            ways = (ways + dp[ind + 1][1])%mod;
                        }
                        else{
                            ways = (ways + dp[ind + 1][2] + dp[ind + 1][0])%mod;
                        }
                    }
                    dp[ind][count] = ways;
                }
            }
        }
        return dp[0][0];
    }
};

//Bottom-Up
//TC: O(n*3)
//SC: O(1)
class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int numberOfWays(string corridor) {
        
        int n = corridor.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(3));
        
        vector<ll> pre(3, 0), curr(3);
        pre[2] = 1;
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int count = 2; count >= 0; count--){
                ll ways = 0;

                if(count == 0){
                    if(corridor[ind] == 'S'){
                        ways = (ways + pre[1])%mod;
                    }
                    else{
                        ways = (ways + pre[0])%mod;
                    }
                }
                else if(count == 1){
                    if(corridor[ind] == 'S'){
                        ways = (ways + pre[2])%mod;
                    }
                    else{
                        ways = (ways + pre[1])%mod;
                    }
                }
                else if(count == 2){
                    if(corridor[ind] == 'S'){
                        ways = (ways + pre[1])%mod;
                    }
                    else{
                        ways = (ways + pre[2] + pre[0])%mod;
                    }
                }
                curr[count] = ways;
            }
            pre = curr;
        }
        return pre[0];
    }
};

//Intuitive
class Solution {
public:
    #define ll long long
    int numberOfWays(string corridor) {
        
        ll count = 0;
        
        for(int i = 0; i < corridor.size(); i++){
            if(corridor[i] == 'S') count++;
        }
        
        if(count == 0 || count  % 2 != 0){
            return 0;
        }
        
        ll temp = 0, ans = 1;
        int mod = 1e9 + 7;
        
        int i = 0;
        
        while(i < corridor.size()){
            
            if(corridor[i] == 'S') temp++;
            if(temp == 2){
                int cnt = 1;
                i++;
                while(i < corridor.size() && corridor[i] == 'P'){
                    cnt++;
                    i++;
                }
                if(i == corridor.size()) break;
                ans = (ans*cnt)%mod;
                temp = 0;
            }else{
                i++;
            }
        }
        return ans;
    }
};
