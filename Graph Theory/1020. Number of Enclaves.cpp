class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void solve(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid, int m, int n){
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                if(vis[xo][yo] == 0 && grid[xo][yo] == 1)
                    solve(xo, yo, vis, grid, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int ones = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    ones++;
                }
            }
        }
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            if(vis[i][0] == 0 && grid[i][0] == 1){
                solve(i, 0, vis, grid, m, n);
            }
        }
        for(int i = 0; i < m; i++){
            if(vis[i][n - 1] == 0 && grid[i][n - 1] == 1){
                solve(i, n - 1, vis, grid, m, n);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(vis[0][i] == 0 && grid[0][i] == 1){
                solve(0, i, vis, grid, m, n);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(vis[m - 1][i] == 0 && grid[m - 1][i] == 1){
                solve(m - 1, i, vis, grid, m, n);
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 1) count++;
            }
        }
        
        return ones - count;
    }
};
