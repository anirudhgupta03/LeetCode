//Top-Down
//TC: O(n*amount)
//SC: O(n*amount) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
        
        if(amount == 0){
            return 1;
        }
        if(ind == coins.size()){
            return 0;
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        int count = 0;
        if(coins[ind] <= amount){
            count += solve(ind, amount - coins[ind], coins, dp);
        }
        count += solve(ind + 1, amount, coins, dp);
        return dp[ind][amount] = count;
    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        return solve(0, amount, coins, dp);
    }
};

//Bottom-Up
//TC: O(n*amount)
//SC: O(n*amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        int dp[n+1][amount+1];
        
        for(int j = 1; j < amount + 1; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < amount + 1; j++){
                
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};

//Bottom-Up
//TC: O(n*amount)
//SC: O(amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<int> pre(amount + 1, 0), curr(amount + 1);
        pre[0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                if(j == 0){
                    curr[j] = 1;
                }
                else if(coins[i - 1] <= j){
                    curr[j] = curr[j - coins[i - 1]] + pre[j];
                }
                else{
                    curr[j] = pre[j];
                }
            }
            pre = curr;
        }
        return curr[amount];
    }
};
