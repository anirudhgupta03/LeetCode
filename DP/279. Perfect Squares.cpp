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
