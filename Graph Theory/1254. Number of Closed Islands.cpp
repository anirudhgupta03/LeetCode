//Method - 1
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<vector<int>> &vis, bool &flag, vector<vector<int>> &grid){
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size()){
                if(grid[xo][yo] == 0 && (xo == 0 || yo == 0 || xo == grid.size() - 1 || yo == grid[0].size() - 1)){
                    flag = false;
                }
                if(grid[xo][yo] == 0 && vis[xo][yo] == 0){
                    dfs(xo, yo, vis, flag, grid);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    bool flag = true;
                    dfs(i, j, vis, flag, grid);
                    if(flag) count++;
                }
            }
        }
        return count;
    }
};

//Method - 2
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<vector<int>> &grid){
        grid[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size() && grid[xo][yo] == 0){
                dfs(xo, yo, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0){
                dfs(i, 0, grid);
            }
            if(grid[i][n - 1] == 0){
                dfs(i, n - 1, grid);
            }
        }
        
        for(int j = 1; j < n - 1; j++){
            if(grid[0][j] == 0){
                dfs(0, j, grid);
            }
            if(grid[m - 1][j] == 0){
                dfs(m - 1, j, grid);
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};
