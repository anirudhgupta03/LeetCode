//Top-Down
//TC: O(n*2)
//SC: O(n*2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, int flag, int fee, vector<int> &prices, vector<vector<int>> &dp){
        
        if(ind == prices.size()){
            return 0;
        }
        if(dp[ind][flag] != -1){
            return dp[ind][flag];
        }
        if(flag){
            return dp[ind][flag] = max(solve(ind + 1, 0, fee, prices, dp) - prices[ind], solve(ind + 1, 1, fee, prices, dp));
        }
        else{
            return dp[ind][flag] = max(solve(ind + 1, 1, fee, prices, dp) + prices[ind] - fee, solve(ind + 1, 0, fee, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};

//Bottom-Up
//TC: O(n*2)
//SC: O(n*2)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        
        for(int ind = n; ind >= 0; ind--){
            for(int flag = 0; flag <= 1; flag++){
                
                if(ind == n){
                    dp[ind][flag] = 0;
                }
                else if(flag){
                    dp[ind][flag] = max(dp[ind + 1][0] - prices[ind], dp[ind + 1][1]);
                }
                else{
                    dp[ind][flag] = max(dp[ind + 1][1] + prices[ind] - fee, dp[ind + 1][0]);
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
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<int> pre(2, 0), curr(2);
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int flag = 0; flag <= 1; flag++){
                if(flag){
                    curr[flag] = max(pre[0] - prices[ind], pre[1]);
                }
                else{
                    curr[flag] = max(pre[1] + prices[ind] - fee, pre[0]);
                }
            }
            pre = curr;
        }
        return pre[1];
    }
};

//Ref: https://www.youtube.com/watch?v=pTQB9wbIpfU
//Intuitive
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int bsp = -prices[0], ssp = 0;
        
        for(int i = 1; i < prices.size(); i++){
            
            int nbsp = 0, nssp = 0;
            
            nbsp = max(bsp, ssp - prices[i]);
            nssp = max(ssp, bsp + prices[i] - fee);
            
            bsp = nbsp;
            ssp = nssp;
        }
        
        return ssp;
    }
};
