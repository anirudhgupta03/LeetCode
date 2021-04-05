class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid){
        
        int n = grid.size(), m = grid[0].size();
        
        if(x < 0 || x >= n || y < 0 || y >= m){
            return false;
        }
        
        if(vis[x][y] == 1 || grid[x][y] == '0'){
            return false;
        }
        return true;
    }
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid){
        
        vis[x][y] = 1;
        
        if(isValid(x,y-1,vis,grid)){
            dfs(x,y-1,vis,grid);
        }
        if(isValid(x,y+1,vis,grid)){
            dfs(x,y+1,vis,grid);
        }
        if(isValid(x-1,y,vis,grid)){
            dfs(x-1,y,vis,grid);
        }
        if(isValid(x+1,y,vis,grid)){
            dfs(x+1,y,vis,grid);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int cc = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    dfs(i,j,vis,grid);
                    cc++;
                }
            }
        }
        return cc;
    }
};
