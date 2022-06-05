//Method - 1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int j = 1; j < amount + 1; j++){
            dp[0][j] = INT_MAX -1;
        }
        
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < amount + 1; j++){
                
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i][j-coins[i-1]] + 1,dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amount] == INT_MAX - 1){
            return -1;
        }
        return dp[n][amount];
    }
};

//Method - 2
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        int dp[n + 1][amount + 1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                
                if(j == 0){
                    dp[i][j] = 0;
                }
                else if(i == 0){
                    dp[i][j] = INT_MAX;
                }
                else if(coins[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j];
                    if(dp[i][j - coins[i - 1]] != INT_MAX){
                        dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
                    }
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};
