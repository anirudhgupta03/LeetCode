//Ref: https://www.youtube.com/watch?v=z6kelCB0ww4
//Recursion + Memoization
class Solution {
public:
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    int findUniquePaths(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int count = 0;
        for(int dir = 0; dir < 2; dir++){
            int di = i + dx[dir], dj = j + dy[dir];
            if(di < m && dj < n && !obstacleGrid[di][dj]){
                count += findUniquePaths(di, dj, m, n, dp, obstacleGrid);
            }
        }
        return dp[i][j] = count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findUniquePaths(0, 0, m, n, dp, obstacleGrid);
    }
};

//Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    if(i >= 1 && !obstacleGrid[i - 1][j]) dp[i][j] += dp[i - 1][j];
                    if(j >= 1 && !obstacleGrid[i][j - 1]) dp[i][j] += dp[i][j - 1]; 
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++){
            vector<int> currdp(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    currdp[j] = 1;
                }
                else{
                    if(i >= 1 && !obstacleGrid[i - 1][j]) currdp[j] += dp[j];
                    if(j >= 1 && !obstacleGrid[i][j - 1]) currdp[j] += currdp[j - 1]; 
                }
            }
            dp = currdp;
        }
        return dp[n - 1];
    }
};
