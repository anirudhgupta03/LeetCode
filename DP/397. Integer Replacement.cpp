class Solution {
public:
    #define ll long long
    int solve(ll n, unordered_map<ll,int> &dp){
        
        if(n == 1){
            return 0;
        }
        
        if(dp.find(n) != dp.end()){
            return dp[n];
        }
        
        int op;
        if(n % 2 == 0){
            op = solve(n/2, dp) + 1;
        }
        else{
            op = min(solve(n - 1, dp), solve(n + 1, dp)) + 1;
        }
        return dp[n] = op;
    }
    int integerReplacement(int n) {
        
        unordered_map<ll,int> dp;
        
        return solve(n, dp);
    }
};
