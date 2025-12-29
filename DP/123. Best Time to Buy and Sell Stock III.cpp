//Top-Down
//TC: O(n*2*2)
//SC: O(n*2*2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, int flag, int count, vector<int> &prices, vector<vector<vector<int>>> &dp){
        
        if(count == 2 || ind == prices.size()){
            return 0;
        }
        
        if(dp[ind][flag][count] != -1){
            return dp[ind][flag][count];
        }
        if(flag){
            return dp[ind][flag][count] = max(-prices[ind] + solve(ind + 1, 0, count, prices, dp), solve(ind + 1, 1, count, prices, dp));
        }
        else{
            return dp[ind][flag][count] = max(solve(ind + 1, 1, count + 1, prices, dp) + prices[ind], solve(ind + 1, 0, count, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,-1)));
        
        return solve(0, 1, 0, prices, dp);
    }
};

//Bottom-Up
//TC: O(n*2*3)
//SC: O(n*2*3)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3,0)));
        
        for(int ind = n; ind >= 0; ind--){
            for(int flag = 0; flag <= 1; flag++){
                for(int count = 2; count >= 0; count--){
                    if(count == 2 || ind == n){
                        dp[ind][flag][count] = 0;
                    }
                    else if(flag){
                        dp[ind][flag][count] = max(-prices[ind] + dp[ind + 1][0][count], dp[ind + 1][1][count]);
                    }
                    else{
                        dp[ind][flag][count] = max(dp[ind + 1][1][count + 1] + prices[ind], dp[ind + 1][0][count]);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};

//Bottom-Up
//TC: O(n*2*3)
//SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> pre(2, vector<int>(3,0)), curr(2,vector<int>(3));
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int flag = 0; flag <= 1; flag++){
                for(int count = 2; count >= 0; count--){
                    if(count == 2 || ind == n){
                        curr[flag][count] = 0;
                    }
                    else if(flag){
                        curr[flag][count] = max(-prices[ind] + pre[0][count], pre[1][count]);
                    }
                    else{
                        curr[flag][count] = max(pre[1][count + 1] + prices[ind], pre[0][count]);
                    }
                }
            }
            pre = curr;
        }
        return pre[1][0];
    }
};

//Another Top-Down
//TC: O(n*2*2)
//SC: O(n*4) + Auxilliary Stack Space
class Solution {
public:
    int findMaxProfit(int ind, int txns, vector<int> &prices, vector<vector<int>> &dp){
        if(ind == prices.size() || txns == 4){
            return 0;
        }
        if(dp[ind][txns] != -1){
            return dp[ind][txns];
        }
        if(txns % 2 == 0){
            int buy = findMaxProfit(ind + 1, txns + 1, prices, dp) - prices[ind];
            int notBuy = findMaxProfit(ind + 1, txns, prices, dp);
            return dp[ind][txns] = max(buy, notBuy);
        }
        else{
            int sell = findMaxProfit(ind + 1, txns + 1, prices, dp) + prices[ind];
            int notSell = findMaxProfit(ind + 1, txns, prices, dp);
            return dp[ind][txns] = max(sell, notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));
        return findMaxProfit(0, 0, prices, dp);
    }
};

//Intuitive
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        int arr1[n], arr2[n];
        
        int minEle = INT_MAX, maxprofit = 0;
        
        for(int i = 0; i < n; i++){
            
            if(prices[i] < minEle){
                minEle = prices[i];
            }
            
            maxprofit = max(maxprofit, prices[i] - minEle);
            
            arr1[i] = maxprofit;
        }
        
        maxprofit = 0;
        int maxEle = INT_MIN;
        
        for(int i = n - 1; i >= 0; i--){
            
            if(prices[i] > maxEle){
                maxEle = prices[i];
            }
            
            maxprofit = max(maxprofit, maxEle - prices[i]);
            
            arr2[i] = maxprofit;
        }
        
        maxprofit = 0;
        
        for(int i = 0; i < n; i++){
            maxprofit = max(maxprofit, arr1[i] + arr2[i]);
        }
        
        return maxprofit;
    }
};
