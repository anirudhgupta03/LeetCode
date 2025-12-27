//Top-Down
//TC: O(n*amount)
//SC: O(n*amount) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        
        if(amount == 0) return 0;
        if(ind == 0) return INT_MAX;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int take = INT_MAX;
        if(coins[ind - 1] <= amount){
            take = solve(ind, coins, amount - coins[ind - 1], dp);
            if(take != INT_MAX) take += 1;
        } 
        
        int notTake = solve(ind - 1, coins, amount, dp);
        return dp[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int minCoins = solve(n, coins, amount, dp);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};

//Bottom-Up
//TC: O(n*amount)
//SC: O(n*amount)
//Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                if(j == 0) dp[i][j] = 0;
                else if(i == 0) dp[i][j] = INT_MAX;
                else{
                    int take = INT_MAX;
                    if(coins[i - 1] <= j){
                        take = dp[i][j - coins[i - 1]];
                        if(take != INT_MAX) take += 1;
                    } 
                    int notTake = dp[i - 1][j];
                    dp[i][j] = min(take, notTake);
                }
            }
        }
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};

//Tabulation + Space Optimization
//TC: O(n*amount)
//SC: O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prevDP(amount + 1, -1);
        for(int i = 0; i <= n; i++){
            vector<int> currDP(amount + 1, -1);
            for(int j = 0; j <= amount; j++){
                if(j == 0) currDP[j] = 0;
                else if(i == 0) currDP[j] = INT_MAX;
                else{
                    int take = INT_MAX;
                    if(coins[i - 1] <= j){
                        take = currDP[j - coins[i - 1]];
                        if(take != INT_MAX) take += 1;
                    } 
                    int notTake = prevDP[j];
                    currDP[j] = min(take, notTake);
                }
            }
            prevDP = currDP;
        }
        return prevDP[amount] == INT_MAX ? -1 : prevDP[amount];
    }
};
