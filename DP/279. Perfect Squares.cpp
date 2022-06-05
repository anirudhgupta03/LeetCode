//Method - 1
//Bottom Up
//Ref: https://www.youtube.com/watch?v=aZuQXkO0-XA&t=5s
class Solution {
public:
    int numSquares(int n) {
        
        int dp[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int j = 1; j *j <= i; j++){
                dp[i] = min(dp[i-j*j] + 1, dp[i]);
            }
        }
        
        return dp[n];
    }
};

//Method - 2
//Top Down
class Solution {
public:
    int solve(int n, vector<int> &dp){
        
        if(n == 0 || n == 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int count = INT_MAX;
        
        for(int i = 1; i <= sqrt(n); i++){
            count = min(count, 1 + solve(n - i*i, dp));
        }
        return dp[n] = count;
    }
    int numSquares(int n) {
        
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
