class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    
    bool isSafe(int x, int y, int m, int n){
        
        if(x < 0 || x >= m || y < 0 || y >= n){
            return false;
        }
        
        return true;
    }
    void dfs(int x, int y, vector<vector<int>> &vis,vector<vector<int>> &grid2, int m, int n,vector<vector<int>> &grid1, bool &flag){
        
        vis[x][y] = 1;
        
        if(grid1[x][y] == 0){
            flag = false;
        }
        for(int i = 0; i < 4; i++){
    
            int newx = x + dx[i], newy = y + dy[i];
            
            if(isSafe(newx,newy,m,n) && grid2[newx][newy] == 1 && vis[newx][newy] == false){
                dfs(newx,newy,vis,grid2,m,n,grid1,flag);
            }
        }
    }
        
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m = grid2.size(), n = grid2[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(grid2[i][j] == 1 && vis[i][j] == 0){
                    bool flag = true;
                    dfs(i,j,vis,grid2,m,n,grid1,flag);
                    if(flag){
                        count++;
                    }
                }
                
            }
        }
        
        return count;
    }
};
