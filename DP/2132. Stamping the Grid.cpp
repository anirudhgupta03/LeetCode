//Ref: https://www.youtube.com/watch?v=4XS2X7u9jus
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        
        int m = grid.size(), n = grid[0].size();
        
        int vis[m][n];
        memset(vis,0,sizeof(vis));
        
        int u[m][n], d[m][n];
        
        for(int j = 0; j < n; j++){
            u[0][j] = 1 - grid[0][j];
            for(int i = 1; i < m; i++){
                if(grid[i][j] == 1) u[i][j] = 0;
                else    u[i][j] = u[i-1][j] + 1;
            }
        }
        
        for(int j = 0; j < n; j++){
            d[m - 1][j] = 1 - grid[m - 1][j];
            for(int i = m - 2; i >= 0; i--){
                if(grid[i][j] == 1) d[i][j] = 0;
                else d[i][j] = d[i + 1][j] + 1;
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 || vis[i][j]) continue;
                int up = INT_MAX, down = INT_MAX;
                int end = j;
                for(int c = j; c < n && grid[i][c] != 1; c++){
                    vis[i][c] = true;
                    end = c;
                    up = min(u[i][c], up);
                    down = min(d[i][c], down);
                }
                
                int w = end - j + 1;
                int h = up + down - 1;
                if(w < stampWidth || h < stampHeight) return false;
            }
        }
        return true;
    }
};
