//Ref: https://www.youtube.com/watch?v=pTQB9wbIpfU
//Method - 1
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

//Method - 2
//Top-Down
class Solution {
public:
    int dp[50001][2];
    int solve(int ind, int flag, int fee, vector<int> &prices){
        
        if(ind == prices.size()){
            return 0;
        }
        
        if(dp[ind][flag] != -1){
            return dp[ind][flag];
        }
        
        int profit;
        if(flag == 0){
            profit = max(solve(ind + 1, 1, fee, prices) - prices[ind], solve(ind + 1, 0, fee, prices));
        }
        else{
            profit = max(solve(ind + 1, 0, fee, prices) + prices[ind] - fee, solve(ind + 1, 1, fee, prices));
        }
        return dp[ind][flag] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, fee, prices);
    }
};

//Method - 3
//Bottom-Up
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, fee, prices);
        
        int n = prices.size();
        
        int dp[n + 1][2];
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int flag = 0; flag <= 1; flag++){
                if(flag == 0){
                    dp[ind][flag] = max(dp[ind + 1][1] - prices[ind], dp[ind + 1][0]);
                }
                else{
                    dp[ind][flag] = max(dp[ind + 1][0] + prices[ind] - fee, dp[ind + 1][1]);
                }
            }
        }
        return dp[0][0];
    }
};
