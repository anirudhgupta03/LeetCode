//Method - 1
class Solution {
public:
    int dx[8] = {-1,1,0,0,-1,-1,1,1};
    int dy[8] = {0,0,-1,1,-1,1,-1,1};
    #define ppiii pair<pair<int,int>,int>
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1){
            return -1;
        }
        
        queue<ppiii> q;
        q.push({{0,0},1});
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                ppiii p = q.front();
                q.pop();
                int x = p.first.first, y = p.first.second, level = p.second;
                
                if(x == n - 1  && y == n - 1){
                    return level;
                }
                if(vis[x][y]) continue;
                vis[x][y] = 1;
                
                for(int i = 0; i < 8; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < n && yo < n){
                        if(grid[xo][yo] == 0 && vis[xo][yo] == 0){
                            q.push({{xo,yo},level+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

//Method - 2
class Solution {
public:
    int dx[8] = {-1,1,0,0,-1,-1,1,1};
    int dy[8] = {0,0,-1,1,-1,1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1){
            return -1;
        }
        
        if(n == 1){
            return 1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int level = 0;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;

                for(int i = 0; i < 8; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < n && yo < n){
                        if(grid[xo][yo] == 0 && vis[xo][yo] == 0){
                            if(xo == n - 1 && yo == n - 1){
                                return level + 2;
                            }
                            vis[xo][yo] = 1;
                            q.push({xo,yo});
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
