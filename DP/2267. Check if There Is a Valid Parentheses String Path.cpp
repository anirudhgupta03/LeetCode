//Ref: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/discuss/2017740/DFS
class Solution {
public:
    int dp[100][100][101];
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    int solve(int x, int y, int m, int n, vector<vector<char>> &grid, int bal){
        
      if(bal < 0 || bal > (m + n)/2){
            return 0;
        }
        if(x == m - 1 && y == n - 1){
            if(bal == 0){
                return dp[x][y][bal] = 1;
            }
            return dp[x][y][bal] = 0;
        }
        if(dp[x][y][bal] != -1){
            return dp[x][y][bal];
        }
        for(int i = 0; i < 2; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo < m && yo < n){
                if(grid[xo][yo] == '('){
                    int flag = solve(xo, yo, m, n, grid, bal + 1);
                    if(flag) return dp[x][y][bal] = 1;
                }
                else{
                    int flag = solve(xo, yo, m, n, grid, bal - 1);
                    if(flag) return dp[x][y][bal] = 1;
                }
            }
        }
        return dp[x][y][bal] = 0;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        if(grid[0][0] == ')' || grid[m - 1][n - 1] == '('){
            return false;
        }
        return solve(0, 0, m, n, grid, 1);
    }
};
