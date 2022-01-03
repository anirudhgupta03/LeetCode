//Top-Down Approach
//TLE
class Solution {
public:
    int solve(int n, int k, vector<vector<int>> &dp, int mod){
        
        if(n == 0){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        
        int count = 0;
        for(int i = 0; i <= min(k, n - 1); i++){
            count = (count + solve(n - 1, k - i, dp, mod))%mod;
        }
        
        return dp[n][k] = count;
    }
    int kInversePairs(int n, int k) {
        
        int mod = 1e9 + 7;
        
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
        
        return solve(n, k, dp, mod);
    }
};
