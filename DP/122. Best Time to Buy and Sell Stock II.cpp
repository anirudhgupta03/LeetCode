//Top-Down
//TC: O(n*2)
//SC: O(n*2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, int flag, vector<int> &prices, vector<vector<int>> &dp){
        
        if(ind == prices.size()){
            return 0;
        }
    
        if(dp[ind][flag] != -1){
            return dp[ind][flag];
        }
        if(flag){
            return dp[ind][flag] = max(solve(ind + 1, 0, prices, dp) - prices[ind], solve(ind + 1, 1, prices, dp));
        }
        else{
            return dp[ind][flag] = max(solve(ind + 1, 1, prices, dp) + prices[ind], solve(ind + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return solve(0, 1, prices, dp);
    }
};

//Bottom-Up
//TC: O(n*2)
//SC: O(n*2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2));
        
        for(int ind = n; ind >= 0; ind--){
            for(int flag = 1; flag >= 0; flag--){
                
                if(ind == n){
                    dp[ind][flag] = 0;
                }
                else if(flag){
                    dp[ind][flag] = max(dp[ind + 1][0] - prices[ind], dp[ind + 1][1]);
                }
                else{
                    dp[ind][flag] = max(dp[ind + 1][1] + prices[ind], dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

//Bottom-Up
//TC: O(n*2)
//SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<int> pre(2,0), curr(2);
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int flag = 1; flag >= 0; flag--){
                
                if(flag){
                    curr[flag] = max(pre[0] - prices[ind], pre[1]);
                }
                else{
                    curr[flag] = max(pre[1] + prices[ind], pre[0]);
                }
            }
            pre = curr;
        }
        return pre[1];
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
