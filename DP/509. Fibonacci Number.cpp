class Solution {
public:
    
    int solve(int n, vector<int> &dp){
        
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int fib(int n) {
        
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = -1;
        }
        
        return solve(n,dp);
    }
};
