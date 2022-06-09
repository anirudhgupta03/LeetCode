//Backtracking Solution
//TLE
class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool isValid(int x, int y, int n){
        if(x >= 0 && y >= 0 && x < n && y < n){
            return true;
        }
        return false;
    }
    void dfs(int x, int y, vector<vector<int>> &grid, int &maxCherries, int cherries, bool &flag){
        
        if(x == 0 && y == 0 && flag){
            maxCherries = max(maxCherries, cherries);
            return;
        }
        
        if(x == grid.size() - 1 && y == grid.size() - 1 && !flag){
            flag = true;
            dfs(x, y, grid, maxCherries, cherries, flag);
            flag = false;
        }
        
        if(!flag){
            for(int i = 0; i < 2; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(isValid(xo, yo, grid.size()) && (grid[xo][yo] == 0 || grid[xo][yo] == 1)){
                    int temp = grid[xo][yo];
                    grid[xo][yo] = 0;
                    dfs(xo, yo, grid, maxCherries, cherries + temp, flag);
                    grid[xo][yo] = temp;
                }
            }
        }
        else{
            for(int i = 2; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(isValid(xo, yo, grid.size()) && (grid[xo][yo] == 0 || grid[xo][yo] == 1)){
                    int temp = grid[xo][yo];
                    grid[xo][yo] = 0;
                    dfs(xo, yo, grid, maxCherries, cherries + temp, flag);
                    grid[xo][yo] = temp;
                }
            }
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        bool flag = false;
        
        int maxCherries = 0, cherries = 0;
        
        if(grid[0][0] == 1){
            grid[0][0] = 0;
            cherries = 1;
        }

        dfs(0, 0, grid, maxCherries, cherries, flag);
        
        return maxCherries;
    }
};

//DP Solution
//4D DP
class Solution {
public:
    int dp[51][51][51][51];
    
    int solve(int r1, int c1, int r2, int c2, int n, vector<vector<int>> &grid){
        
        if(r1 == n - 1 && c1 == n - 1){
            return grid[r1][c1];
        }
        
        if(dp[r1][c1][r2][c2] != -1){
            return dp[r1][c1][r2][c2];
        }
        int cherries = INT_MIN;
    
        if(r1 + 1 < n && r2 + 1 < n && grid[r1 + 1][c1] != -1 && grid[r2 + 1][c2] != -1){
            int temp = solve(r1 + 1, c1, r2 + 1, c2, n, grid);
            if(temp != INT_MIN){
                if(r1 == r2 && c1 == c2){
                    cherries = max(cherries, temp + grid[r1][c1]);
                }
                else{
                    cherries = max(cherries, temp + grid[r1][c1] + grid[r2][c2]);
                }
            }
        } 
        
        if(r1 + 1 < n && c2 + 1 < n && grid[r1 + 1][c1] != -1 && grid[r2][c2 + 1] != -1){
            int temp = solve(r1 + 1, c1, r2, c2 + 1, n, grid);
            if(temp != INT_MIN){
                if(r1 == r2 && c1 == c2){
                    cherries = max(cherries, temp + grid[r1][c1]);
                }
                else{
                    cherries = max(cherries, temp + grid[r1][c1] + grid[r2][c2]);
                }
            }
        }
        
        if(c1 + 1 < n && r2 + 1 < n && grid[r1][c1 + 1] != -1 && grid[r2 + 1][c2] != -1){
            int temp = solve(r1, c1 + 1, r2 + 1, c2, n, grid);
            if(temp != INT_MIN){
                if(r1 == r2 && c1 == c2){
                    cherries = max(cherries, temp + grid[r1][c1]);
                }
                else{
                    cherries = max(cherries, temp + grid[r1][c1] + grid[r2][c2]);
                }
            }
        }
        
        if(c1 + 1 < n && c2 + 1 < n && grid[r1][c1 + 1] != -1 && grid[r2][c2 + 1] != -1){
            int temp = solve(r1, c1 + 1, r2, c2 + 1, n, grid);
            if(temp != INT_MIN){
                if(r1 == r2 && c1 == c2){
                    cherries = max(cherries, temp + grid[r1][c1]);
                }
                else{
                    cherries = max(cherries, temp + grid[r1][c1] + grid[r2][c2]);
                }
            }
        }
        return dp[r1][c1][r2][c2] = cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        memset(dp, -1, sizeof(dp));
        
        int res = solve(0, 0, 0, 0, n, grid);
        
        if(res == INT_MIN){
            return 0;
        }
        return res;
    }
};

//Further Optimisation
//3D DP
class Solution {
public:
    int dp[51][51][51];
    int solve(int r1, int c1, int r2, vector<vector<int>> &grid){
        
        int c2 = r1 + c1 - r2;
        
        if(r1 == grid.size() - 1 && c1 == grid[0].size() - 1){
            return grid[r1][c1];
        }
        
        if(dp[r1][c1][r2] != -1){
            return dp[r1][c1][r2];
        }
        int maxCherries = INT_MIN;
        
        if(r1 + 1 < grid.size() && r2 + 1 < grid.size() && grid[r1 + 1][c1] != -1 && grid[r2 + 1][c2] != -1){
            int res = solve(r1 + 1, c1, r2 + 1, grid);
            if(res != INT_MIN){
                if(r1 == r2 && c1 == c2) maxCherries = max(maxCherries, res + grid[r1][c1]);
                else maxCherries = max(maxCherries, res + grid[r1][c1] + grid[r2][c2]);
            }
        }
        
        if(r1 + 1 < grid.size() && c2 + 1 < grid.size() && grid[r1 + 1][c1] != -1 && grid[r2][c2 + 1] != -1){
            int res = solve(r1 + 1, c1, r2, grid);
            if(res != INT_MIN){
                if(r1 == r2 && c1 == c2) maxCherries = max(maxCherries, res + grid[r1][c1]);
                else maxCherries = max(maxCherries, res + grid[r1][c1] + grid[r2][c2]);
            }
        }
        
        if(c1 + 1 < grid.size() && r2 + 1 < grid.size() && grid[r1][c1 + 1] != -1 && grid[r2 + 1][c2] != -1){
            int res = solve(r1, c1 + 1, r2 + 1, grid);
            if(res != INT_MIN){
                if(r1 == r2 && c1 == c2) maxCherries = max(maxCherries, res + grid[r1][c1]);
                else maxCherries = max(maxCherries, res + grid[r1][c1] + grid[r2][c2]);
            }
        }
        
        if(c1 + 1 < grid.size() && c2 + 1 < grid.size() && grid[r1][c1 + 1] != -1 && grid[r2][c2 + 1] != -1){
            int res = solve(r1, c1 + 1, r2, grid);
            if(res != INT_MIN){
                if(r1 == r2 && c1 == c2) maxCherries = max(maxCherries, res + grid[r1][c1]);
                else maxCherries = max(maxCherries, res + grid[r1][c1] + grid[r2][c2]);
            }
        }
        return dp[r1][c1][r2] = maxCherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int res = solve(0, 0, 0, grid);
        if(res == INT_MIN) return 0;
        return res;
    }
};
