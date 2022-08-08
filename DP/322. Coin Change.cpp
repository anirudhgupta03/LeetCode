//Top-Down
//TC: O(n*amount)
//SC: O(n*amount) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
        
        if(amount == 0){
            return 0;
        }
        if(ind == coins.size()){
            return INT_MAX;
        }
        
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        if(coins[ind] <= amount){
            int take = solve(ind, amount - coins[ind], coins, dp);
            int nottake = solve(ind + 1, amount, coins, dp);
            if(take != INT_MAX){
                return dp[ind][amount] = min(take + 1, nottake);
            }
            else{
                return dp[ind][amount] = nottake;
            }
        }
        return dp[ind][amount] = INT_MAX;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = solve(0, amount, coins, dp);
        if(res == INT_MAX) return -1;
        return res;
    }
};

//Bottom-Up
//TC: O(n*amount)
//SC: O(n*amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        
        for(int i = n; i >= 0; i--){
            for(int j = 0; j <= amount; j++){
                if(j == 0){
                    dp[i][j] = 0;
                }
                else if(i == n){
                    dp[i][j] = INT_MAX;
                }
                else if(coins[i] <= j){
                    
                    int take = dp[i][j - coins[i]];
                    int nottake = dp[i + 1][j];
                    
                    if(take != INT_MAX){
                        dp[i][j] = min(take + 1, nottake);
                    }
                    else{
                        dp[i][j] = nottake;
                    }
                }
                else{
                    dp[i][j] = INT_MAX;
                }
            }
        }
        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }
};

//Intuitive Method - 1
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

//Intuitive Method - 2
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
