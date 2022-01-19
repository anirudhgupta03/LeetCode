class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    bool dfs(char ch, int parx, int pary, int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid){
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size() && grid[xo][yo] == ch){
                if(vis[xo][yo]){
                    if(xo != parx || yo != pary){
                        return true;
                    }
                }
                else{
                    bool flag = dfs(ch, x, y, xo, yo, vis, grid);
                    if(flag){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0){
                    bool flag = dfs(grid[i][j], -1,-1,i,j,vis,grid);
                    if(flag){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
