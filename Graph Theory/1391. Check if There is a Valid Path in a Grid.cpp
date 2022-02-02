class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int dir[4] = {0,1,2,3};
    
    bool dfs(int x, int y, int direction, vector<vector<int>> &grid, vector<vector<int>> &vis, int m, int n){
        
        if(x == m && y == n - 1 || x == m - 1 && y == n){
            return true;
        }
        
        if(x == m - 1 && y == n - 1){
            if(direction == 3){
                if(grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 5){
                    return true;
                }
            }
            else if(direction == 1){
                if(grid[x][y] == 2 || grid[x][y] == 5 || grid[x][y] == 6){
                    return true;
                } 
            }
        }
        if(!(x >= 0 && y >= 0 && x < m && y < n)){
            return false;
        }
        if(vis[x][y]) return false;
        vis[x][y] = 1;
        
        if(grid[x][y] == 1){
            if(direction == 2 || direction == 3){
                int xo = x + dx[direction], yo = y + dy[direction];        
                bool flag = dfs(xo, yo, direction, grid, vis, m, n);
                if(flag) return true;
            }
        }
        else if(grid[x][y] == 2){
            if(direction == 0 || direction == 1){
                int xo = x + dx[direction], yo = y + dy[direction];
                bool flag = dfs(xo, yo, direction, grid, vis, m, n);
                if(flag) return true;
            }
        }
        else if(grid[x][y] == 3){
            if(direction == 3){
                int xo = x + dx[1], yo = y + dy[1];
                bool flag = dfs(xo, yo, 1, grid, vis, m, n);
                if(flag) return true;
            }
            else if(direction == 0){
                int xo = x + dx[2], yo = y + dy[2];
                bool flag = dfs(xo, yo, 2, grid, vis, m, n);
                if(flag) return true;
            }
        }
        else if(grid[x][y] == 4){
            if(direction == 2){
                int xo = x + dx[1], yo = y + dy[1];
                bool flag = dfs(xo, yo, 1, grid, vis, m, n);
                if(flag) return true;
            }
            else if(direction == 0){
                int xo = x + dx[3], yo = y + dy[3];
                bool flag = dfs(xo, yo, 3, grid, vis, m, n);
                if(flag) return true;
            }
        }
        else if(grid[x][y] == 5){
            if(direction == 3){
                int xo = x + dx[0], yo = y + dy[0];
                bool flag = dfs(xo, yo, 0, grid, vis, m, n);
                if(flag) return true;
            }
            else if(direction == 1){
                int xo = x + dx[2], yo = y + dy[2];
                bool flag = dfs(xo, yo, 2, grid, vis, m, n);
                if(flag) return true;
            }
        }
        else{
            if(direction == 2){
                int xo = x + dx[0], yo = y + dy[0];
                bool flag = dfs(xo, yo, 0, grid, vis, m, n);
                if(flag) return true;
            }
            else if(direction == 1){
                int xo = x + dx[3], yo = y + dy[3];
                bool flag = dfs(xo, yo, 3, grid, vis, m, n);
                if(flag) return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        bool flag = false;
        
        for(int i = 0; i < 4; i++){
            vector<vector<int>> vis(m, vector<int>(n, 0));
            flag = dfs(0, 0, i, grid, vis, m, n);
            if(flag) return true;
        }
        return false;
    }
};

//Using switch
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int dir[4] = {0,1,2,3};
    char dc[4] = {'U','D','L','R'};
    
    bool dfs(int x, int y, int direction, vector<vector<int>> &grid, vector<vector<int>> &vis, int m, int n){
        
        if(x == m && y == n - 1 || x == m - 1 && y == n){
            return true;
        }
        
        if(x == m - 1 && y == n - 1){
            if(direction == 3){
                if(grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 5){
                    return true;
                }
            }
            else if(direction == 1){
                if(grid[x][y] == 2 || grid[x][y] == 5 || grid[x][y] == 6){
                    return true;
                } 
            }
        }
        if(!(x >= 0 && y >= 0 && x < m && y < n)){
            return false;
        }
        if(vis[x][y]) return false;
        vis[x][y] = 1;
        
        switch(grid[x][y]){
            case 1:
                if(direction == 2 || direction == 3){
                     int xo = x + dx[direction], yo = y + dy[direction];
                     bool flag = dfs(xo, yo, direction, grid, vis, m, n);
                     if(flag) return true;
                }
                break;
            case 2:
                if(direction == 0 || direction == 1){
                     int xo = x + dx[direction], yo = y + dy[direction];
                     bool flag = dfs(xo, yo, direction, grid, vis, m, n);
                     if(flag) return true;
                }
                break;
            case 3:
                if(direction == 3){
                     int xo = x + dx[1], yo = y + dy[1];
                     bool flag = dfs(xo, yo, 1, grid, vis, m, n);
                     if(flag) return true;
                }
                else if(direction == 0){
                    int xo = x + dx[2], yo = y + dy[2];
                    bool flag = dfs(xo, yo, 2, grid, vis, m, n);
                    if(flag) return true;
                }
                break;
            case 4:
                if(direction == 2){
                    int xo = x + dx[1], yo = y + dy[1];
                    bool flag = dfs(xo, yo, 1, grid, vis, m, n);
                    if(flag) return true;
                }
                else if(direction == 0){
                    int xo = x + dx[3], yo = y + dy[3];
                    bool flag = dfs(xo, yo, 3, grid, vis, m, n);
                    if(flag) return true;
                }
                break;
            case 5:
                if(direction == 3){
                   int xo = x + dx[0], yo = y + dy[0];
                   bool flag = dfs(xo, yo, 0, grid, vis, m, n);
                   if(flag) return true;
                }
                else if(direction == 1){
                  int xo = x + dx[2], yo = y + dy[2];
                  bool flag = dfs(xo, yo, 2, grid, vis, m, n);
                  if(flag) return true;
                }
            case 6:
                if(direction == 2){
                  int xo = x + dx[0], yo = y + dy[0];
                  bool flag = dfs(xo, yo, 0, grid, vis, m, n);
                  if(flag) return true;
                }
                else if(direction == 1){
                  int xo = x + dx[3], yo = y + dy[3];
                  bool flag = dfs(xo, yo, 3, grid, vis, m, n);
                  if(flag) return true;
                }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        bool flag = false;
        
        for(int i = 0; i < 4; i++){
            vector<vector<int>> vis(m, vector<int>(n, 0));
            flag = dfs(0, 0, i, grid, vis, m, n);
            if(flag) return true;
        }
        return false;
    }
};
