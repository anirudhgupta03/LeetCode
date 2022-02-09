//Ref: https://www.youtube.com/watch?v=DHPg2h589MY
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int vis[31][31];
    void dfs(int x, int y, vector<vector<int>> &grid){
        
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size()){
                if(vis[xo][yo] == 0 && grid[xo][yo] == 1){
                    dfs(xo, yo, grid);
                }
            }
        }
    }
    int minDays(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        memset(vis,0,sizeof(vis));
        
        int islands = 0, ones = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    islands++;
                    dfs(i, j, grid);
                }
                if(grid[i][j] == 1){
                    ones++;
                }
            }
        }
      
        if(islands != 1){
            return 0;
        }
        
        if(m == 1 || n == 1 || ones <= 2){
            if(ones == 2){
                return 2;
            }
            else{
                return 1;
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                   
                    grid[i][j] = 0;
                    islands = 0;
                    memset(vis,0,sizeof(vis));
                    
                    for(int k = 0; k < m; k++){
                        for(int l = 0; l < n; l++){
                            if(vis[k][l] == 0 && grid[k][l] == 1){
                                islands++;
                                dfs(k, l, grid);
                            }
                        }
                    }
                    if(islands > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
