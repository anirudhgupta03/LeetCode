//Ref: Hint
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid){
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size()){
                if(vis[xo][yo] == 0 && grid[xo][yo] == grid[x][y]){
                    dfs(xo, yo, vis, grid);
                }
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        dfs(row, col, vis, grid);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j]){
                    bool flag = false;
                    for(int k = 0; k < 4; k++){
                        int io = i + dx[k], jo = j + dy[k];
                        if(!(io >= 0 && jo >= 0 && io < m && jo < n)){  //Out of Bounds
                            flag = true;
                            break;
                        }
                        if(io >= 0 && jo >= 0 && io < m && jo < n){     //Different Color
                            if(vis[io][jo] == 0){
                                flag = true;
                                break;
                            }
                        }
                    }
                    if(flag){
                        grid[i][j] = color;
                    }
                }
            }
        }
        return grid;
    }
};
