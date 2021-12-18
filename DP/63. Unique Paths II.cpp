//Top-Down Approach
class Solution {
public:
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    
    int solve(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int m, int n){
        
        if(x == m - 1 && y == n - 1){
            return 1;
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        int count = 0;
        
        for(int i = 0; i < 2; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo < m && yo < n && xo >= 0 && yo >= 0){
                if(obstacleGrid[xo][yo] == 0 && vis[xo][yo] == 0){
                    vis[xo][yo] = 1;
                    count += solve(xo, yo, vis, obstacleGrid, dp, m, n);
                    vis[xo][yo] = 0;
                }
            }
        }
        return dp[x][y] = count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
      
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dp(m, vector<int>(n,-1));
        vis[0][0] = 1;
        
        return solve(0,0,vis,obstacleGrid, dp, m, n);
    }
};

//Bottom-Up Approach
//Ref: https://www.youtube.com/watch?v=z6kelCB0ww4
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int dp[rows][cols];
        
        bool flag = false;
        //Fill  1st row
        for(int i=0;i<cols;++i)
        {
            if(flag || obstacleGrid[0][i]==1)
            {
                flag = true;
                dp[0][i] = 0;
            }
            else
                dp[0][i] = 1;
        }
        
        //Fill 1st column
        flag = false;
        for(int i=0;i<rows;++i)
        {
            if(flag || obstacleGrid[i][0]==1)
            {
                flag = true;
                dp[i][0] = 0;
            }
            else
                dp[i][0] = 1;
        }
        
        for(int i=1;i<rows;++i)
        {
            for(int j=1;j<cols;++j)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[rows-1][cols-1];
    }
};
