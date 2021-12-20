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
