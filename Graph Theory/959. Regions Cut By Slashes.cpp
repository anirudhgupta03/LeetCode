//Ref: https://leetcode.com/problems/regions-cut-by-slashes/discuss/205674/DFS-on-upscaled-grid
//Expert Problem
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<vector<int>> &upscale, vector<vector<int>> &vis){
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < upscale.size() && yo < upscale.size()){
                if(upscale[xo][yo] == 0 && vis[xo][yo] == 0){
                    dfs(xo, yo, upscale, vis);
                }
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size(), regions = 0;
        
        vector<vector<int>> upscale(3*n, vector<int>(3*n, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    upscale[3*i][j*3 + 2] = upscale[3*i + 1][3*j + 1] = upscale[3*i + 2][3*j] = 1;
                }
                else if(grid[i][j] == '\\'){
                    upscale[3*i][j*3] = upscale[3*i + 1][3*j + 1] = upscale[3*i + 2][3*j + 2] = 1;
                }
            }
        }
        
        vector<vector<int>> vis(3*n, vector<int>(3*n, 0));
        
        for(int i = 0; i < 3*n; i++){
            for(int j = 0; j < 3*n; j++){
                if(upscale[i][j] == 0 && vis[i][j] == 0){
                    dfs(i, j,  upscale, vis);
                    regions++;
                }
            }
        }
        return regions;
    }
};
