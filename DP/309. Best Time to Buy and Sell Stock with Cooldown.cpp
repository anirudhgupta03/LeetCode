//Top-Down
//TC: O(n*2)
//SC: O(n*2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, int flag, vector<int> &prices, vector<vector<int>> &dp){
        
        if(ind >= prices.size()){
            return 0;
        }
        
        if(dp[ind][flag] != -1){
            return dp[ind][flag];
        }
        
        if(flag){
            return dp[ind][flag] = max(solve(ind + 1, 0, prices, dp) - prices[ind], solve(ind + 1, 1, prices, dp));
        }
        else{
            return dp[ind][flag] = max(solve(ind + 2, 1, prices, dp) + prices[ind], solve(ind + 1, 0, prices, dp));
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
            for(int flag = 0; flag <= 1; flag++){
                if(ind == n){
                    dp[ind][flag] = 0;
                }
                else if(flag){
                    dp[ind][flag] = max(dp[ind + 1][0] - prices[ind], dp[ind + 1][1]);
                }
                else{
                    int val = (ind + 2 <= n) ? dp[ind + 2][1] : 0;
                    dp[ind][flag] = max(val + prices[ind], dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

//Intuitive
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

//Intuitive
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
