//Recursion + Memoization
class Solution {
public:
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    int solve(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(x == grid.size() - 1 && y == grid[0].size() - 1){
            return grid[x][y];
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        int temp = INT_MAX;
        for(int i = 0; i < 2; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo < grid.size() && yo < grid[0].size()){
                temp = min(temp, solve(xo,yo,grid,dp) + grid[x][y]);
            }
        }
        return dp[x][y] = temp;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,grid,dp);
    }
};

//Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int minSum = INT_MAX;
                    if(i >= 1) minSum = min(minSum, dp[i - 1][j]);
                    if(j >= 1) minSum = min(minSum, dp[i][j - 1]);
                    dp[i][j] = minSum + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,0);
        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                }
                else{
                    int minSum = INT_MAX;
                    if(i >= 1) minSum = min(minSum, dp[j]);
                    if(j >= 1) minSum = min(minSum, curr[j - 1]);
                    curr[j] = minSum + grid[i][j];
                }
            }
            dp = curr;
        }
        return dp[n - 1];
    }
};
