//Top-Down
//TC: O(n*2)
//SC: O(n*2) + Auxilliary Stack Space
class Solution {
public:
    int findMaxProfit(int ind, bool flag, vector<int>& prices, vector<vector<int>>& dp){
        
        if(ind == prices.size()) return 0;
        
        if(dp[ind][flag] != -1) return dp[ind][flag];
        
        if(flag){
            int buy = findMaxProfit(ind + 1, 0, prices, dp) - prices[ind];
            int notBuy = findMaxProfit(ind + 1, 1, prices, dp);
            return dp[ind][flag] = max(buy, notBuy);
        }
        else{
            int sell = findMaxProfit(ind + 1, 1, prices, dp) + prices[ind];
            int notSell = findMaxProfit(ind + 1, 0, prices, dp);
            return dp[ind][flag] = max(sell, notSell);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findMaxProfit(0, 1, prices, dp);
    }
};

//Bottom-Up
//Tabulation
//TC: O(n*2)
//SC: O(n*2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        for(int ind = n; ind >= 0; ind--){
            for(int flag = 0; flag <= 1; flag++){
                if(ind == n){
                    dp[ind][flag] = 0;
                }
                else if(flag){
                    int buy = dp[ind + 1][0] - prices[ind];
                    int notBuy = dp[ind + 1][1];
                    dp[ind][flag] = max(buy, notBuy);
                }
                else{
                    int sell = dp[ind + 1][1] + prices[ind];
                    int notSell = dp[ind + 1][0];
                    dp[ind][flag] = max(sell, notSell);
                }
            }
        }
        
        return dp[0][1];
    }
};

//Bottom-Up
//Tabulation + Space Optimization
//TC: O(n*2)
//SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> prevDP(2, 0);
        
        for(int ind = n; ind >= 0; ind--){
            vector<int> currDP(2, 0);
            for(int flag = 0; flag <= 1; flag++){
                if(ind == n){
                    currDP[flag] = 0;
                }
                else if(flag){
                    currDP[flag] = max(prevDP[0] - prices[ind], prevDP[1]);
                }
                else{
                    currDP[flag] = max(prevDP[1] + prices[ind], prevDP[0]);
                }
            }
            prevDP = currDP;
        }
        return prevDP[1];
    }
};

//Intuitive
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                maxProfit += prices[i] - prices[i-1];
            }
        }
        
        return maxProfit;
    }
};
