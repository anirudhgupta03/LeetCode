class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, int &count){
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && xo < grid.size() && yo >= 0 && yo < grid[0].size()){
                if(vis[xo][yo] == 0 && grid[xo][yo] == 1){
                    count++;
                    vis[xo][yo] = 1;
                    dfs(xo, yo, grid, vis, count);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxcount = 0;
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int count = 1;
                    
                    dfs(i,j,grid,vis,count);
                    maxcount = max(maxcount, count);
                }
            }
        }
        return maxcount;
    }
};
