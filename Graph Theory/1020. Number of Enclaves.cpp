//BFS Solution
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    if(board[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    if(board[nx][ny] == 1 && vis[nx][ny] == 0){
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 1 && vis[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//Method - 1
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void solve(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid, int m, int n){
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                if(vis[xo][yo] == 0 && grid[xo][yo] == 1)
                    solve(xo, yo, vis, grid, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int ones = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    ones++;
                }
            }
        }
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            if(vis[i][0] == 0 && grid[i][0] == 1){
                solve(i, 0, vis, grid, m, n);
            }
        }
        for(int i = 0; i < m; i++){
            if(vis[i][n - 1] == 0 && grid[i][n - 1] == 1){
                solve(i, n - 1, vis, grid, m, n);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(vis[0][i] == 0 && grid[0][i] == 1){
                solve(0, i, vis, grid, m, n);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(vis[m - 1][i] == 0 && grid[m - 1][i] == 1){
                solve(m - 1, i, vis, grid, m, n);
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 1) count++;
            }
        }
        
        return ones - count;
    }
};

//Method - 2
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<vector<int>> &grid){
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size() && grid[xo][yo] == 1){
                dfs(xo, yo, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, grid);
            }
            if(grid[i][n - 1] == 1){
                dfs(i, n - 1, grid);
            }
        }
        
        for(int j = 1; j < n - 1; j++){
            if(grid[0][j] == 1){
                dfs(0, j, grid);
            }
            if(grid[m - 1][j] == 1){
                dfs(m - 1, j, grid);
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};
