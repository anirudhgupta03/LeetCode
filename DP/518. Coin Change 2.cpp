//Top-Down
//TC: O(n*amount)
//SC: O(n*amount) + Auxilliary Stack Space
class Solution {
public:
    int findWaysToChange(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(ind == 0) return 0;
        
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int take = 0;
        if(coins[ind - 1] <= amount){
            take = findWaysToChange(ind, amount - coins[ind - 1], coins, dp);
        }
        int notTake = findWaysToChange(ind - 1, amount, coins, dp);
        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return findWaysToChange(n, amount, coins, dp);
    }
};

//Bottom-Up
//TC: O(n*amount)
//SC: O(n*amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<double>> dp(n + 1, vector<double>(amount + 1, 0));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else{
                    double take = 0;
                    if(coins[i - 1] <= j){
                        take = dp[i][j - coins[i - 1]];
                    }
                    double notTake = dp[i - 1][j];
                    dp[i][j] = take + notTake;
                }
            }
        }
        return (int)dp[n][amount];
    }
};

//Bottom-Up (Tabulation + Space Optimization)
//TC: O(n*amount)
//SC: O(amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<double> prevDP(amount + 1, 0);
        for(int i = 0; i <= n; i++){
            vector<double> currDP(amount + 1, 0);
            for(int j = 0; j <= amount; j++){
                if(j == 0){
                    currDP[j] = 1;
                }
                else if(i == 0){
                    currDP[j] = 0;
                }
                else{
                    double take = 0;
                    if(coins[i - 1] <= j){
                        take = currDP[j - coins[i - 1]];
                    }
                    double notTake = prevDP[j];
                    currDP[j] = take + notTake;
                }
            }
            prevDP = currDP;
        }
        return (int)prevDP[amount];
    }
};
