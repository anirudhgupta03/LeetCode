//Top-Down
//TC: O(n*2*k)
//SC: O(n*2*k) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, int flag, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        
        if(ind == prices.size() || k == 0){
            return 0;
        }
        if(dp[ind][flag][k] != -1){
            return dp[ind][flag][k];
        }
        
        if(flag){
            return dp[ind][flag][k] = max(solve(ind + 1, 0, k, prices, dp) - prices[ind], solve(ind + 1, 1, k, prices, dp));
        }
        else{
            return dp[ind][flag][k] = max(solve(ind + 1, 1, k - 1, prices, dp) + prices[ind], solve(ind + 1, 0, k, prices, dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        
        return solve(0, 1, k, prices, dp);
    }
};

//Bottom-Up
//TC: O(n*2*k)
//SC: O(n*2*k)
class Solution {
public:
    int maxProfit(int tk, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(tk + 1)));
        
        for(int ind = n; ind >= 0; ind--){
            for(int flag = 0; flag <= 1; flag++){
                for(int k = 0; k <= tk; k++){
                    if(ind == n || k == 0){
                        dp[ind][flag][k] = 0;
                    }
                    else if(flag){
                        dp[ind][flag][k] = max(dp[ind + 1][0][k] - prices[ind], dp[ind + 1][1][k]);
                    }
                    else{
                        dp[ind][flag][k] = max(dp[ind + 1][1][k - 1] + prices[ind], dp[ind + 1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][tk];
    }
};

//Bottom-Up
//TC: O(n*2*k)
//SC: O(2*k)
class Solution {
public:
    int maxProfit(int tk, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> pre(2, vector<int>(tk + 1, 0)), curr(2, vector<int>(tk + 1));
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int flag = 0; flag <= 1; flag++){
                for(int k = 0; k <= tk; k++){
                    if(ind == n || k == 0){
                        curr[flag][k] = 0;
                    }
                    else if(flag){
                        curr[flag][k] = max(pre[0][k] - prices[ind], pre[1][k]);
                    }
                    else{
                        curr[flag][k] = max(pre[1][k - 1] + prices[ind], pre[0][k]);
                    }
                }
            }
            pre = curr;
        }
        return pre[1][tk];
    }
};

//Approach - 1
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        if(n == 0) return 0;
        
        int dp[k+1][n];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i <= k; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    for(int p = 0; p < j; p++){
                       if(prices[p] < prices[j]){
                           dp[i][j] = max(dp[i][j], dp[i-1][p] + prices[j] - prices[p]);
                       } 
                    }
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        
        for(int i = 0; i <= k; i++){
            for(int j = 0; j < n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[k][n-1];
    }
};

//Approach - 2
//Optimal Approach
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        if(n == 0) return 0;
        
        int dp[k+1][n];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i <= k; i++){
            int diff = INT_MIN;
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    diff = max(diff, dp[i-1][j-1] - prices[j-1]);
                    dp[i][j] = max(dp[i][j], diff + prices[j]);
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        
        for(int i = 0; i <= k; i++){
            for(int j = 0; j < n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[k][n-1];
    }
};
