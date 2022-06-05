//Method - 1
//Top Down
class Solution {
public:
    int solve(int day, int buy, int sold, vector<vector<vector<int>>> &dp, vector<int> &prices){
        
        if(day >= prices.size()){
            return 0;
        }
        
        if(dp[day][buy][sold] != -1){
            return dp[day][buy][sold];
        }
        
        int maxProfit = 0;
        
        if(buy == 0){
            for(int i = day; i < prices.size(); i++){
                maxProfit = max(maxProfit, solve(i, 1, 0, dp, prices));
            }
        }
        else if(sold == 0){
            for(int i = day + 1; i < prices.size(); i++){
                maxProfit = max(maxProfit, solve(i + 2, 0, 1, dp, prices) + prices[i] - prices[day]);
            }
        }
        return dp[day][buy][sold] = maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        if(n == 1) return 0;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        
        return solve(0, 0, 0, dp, prices);
    }
};

//Method - 2
//Optimised Top Down
class Solution {
public:
    int solve(int day, int buy, vector<vector<int>> &dp, vector<int> &prices){
        
        if(day >= prices.size()){
            return 0;
        }
        
        if(dp[day][buy] != -1){
            return dp[day][buy];
        }
        
        int maxProfit = 0;
        
        if(buy == 0){
            for(int i = day; i < prices.size(); i++){
                maxProfit = max(maxProfit, solve(i, 1, dp, prices));
            }
        }
        else{
            for(int i = day + 1; i < prices.size(); i++){
                maxProfit = max(maxProfit, solve(i + 2, 0, dp, prices) + prices[i] - prices[day]);
            }
        }
        return dp[day][buy] = maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        if(n == 1) return 0;
        
        vector<vector<int>> dp(n, vector<int>(2,-1));
        
        return solve(0, 0, dp, prices);
    }
};

//Method - 3
//Bottom Up
//Ref: https://www.youtube.com/watch?v=GY0O57llkKQ&t=13s
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int obsp = -arr[0];
        int ossp = 0;
        int ocsp = 0;
        
        for(int i = 1; i < arr.size(); i++){
            
            int nbsp = 0;
            int nssp = 0;
            int ncsp = 0;
            
            if(ocsp - arr[i] > obsp){
                nbsp = ocsp - arr[i];
            }
            else{
                nbsp = obsp;
            }
            
            if(obsp + arr[i] > ossp){
                nssp = obsp + arr[i];
            }
            else{
                nssp = ossp;
            }
            
            if(ossp > ocsp){
                ncsp = ossp;
            }
            else{
                ncsp = ocsp;
            }
            
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
        return ossp;
    }
}; 

//Method - 4
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = p rices.size();
        int dp[n][3];
        
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return dp[n - 1][1];
    }
};
