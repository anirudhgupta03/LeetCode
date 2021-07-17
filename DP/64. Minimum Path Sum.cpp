class Solution {
public:
    int dx[4] = {1,0};
    int dy[4] = {0,1};
    
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
