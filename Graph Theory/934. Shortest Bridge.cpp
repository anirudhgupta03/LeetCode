//Ref: https://www.youtube.com/watch?v=VuNzLtd8PBg
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid, queue<pair<int,int>> &q){
        
        q.push({x,y});
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid.size()){
                if(vis[xo][yo] == 0 && grid[xo][yo] == 1){
                    dfs(xo, yo, vis, grid, q);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        bool flag = false;
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    flag = true;
                    dfs(i, j, vis, grid, q);
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for(int i = 0; i < 4; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid.size()){
                        if(vis[xo][yo] == 0 && grid[xo][yo] == 1){
                            return level;
                        }
                        else if(vis[xo][yo] == 0 && grid[xo][yo] == 0){
                            vis[xo][yo] = 1;      //Add this to avoid TLE
                            q.push({xo, yo});
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
