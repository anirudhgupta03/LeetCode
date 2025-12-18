//Recursion + Memoization
class Solution {
public:
    int dx[3] = {1,1,1};
    int dy[3] = {-1,0,1};
    int n, m;
    int dp[71][71][71];
    bool isValid(int x, int y1, int y2){
        if(x < n && y1 >= 0 && y2 >= 0 && y1 < m && y2 < m) return true;
        return false;
    }
    int solve(int x, int y1, int y2, vector<vector<int>>& grid){
        if(x == grid.size() - 1){
            if(y1 == y2) return grid[x][y1];
            return grid[x][y1] + grid[x][y2];
        }
        if(dp[x][y1][y2] != -1){
            return dp[x][y1][y2];
        }
        int maxCherries = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int xo = x + dx[i], dy1 = y1 + dy[i];
                int dy2 = y2 + dy[j];
                if(isValid(xo, dy1, dy2)){
                    maxCherries = max(maxCherries, solve(xo, dy1, dy2, grid));
                }
            }
        }
        maxCherries += grid[x][y1];
        if(y1 != y2){
            maxCherries += grid[x][y2];
        }
        return dp[x][y1][y2] = maxCherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        n = rows;
        m = cols;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, cols - 1, grid);
    }
};

//Tabulation
class Solution {
public:
    int dx[3] = {1,1,1};
    int dy[3] = {-1,0,1};
    bool isValid(int x, int y1, int y2){
        if(x < n && y1 >= 0 && y2 >= 0 && y1 < m && y2 < m) return true;
        return false;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m][m];
        memset(dp, 0, sizeof(dp));
        for(int x = n - 1; x >= 0; x--){
            for(int y1 = 0; y1 < m; y1++){
                for(int y2 = 0; y2 < m; y2++){
                    if(x == n - 1){
                        if(y1 == y2) dp[x][y1][y2] = grid[x][y1];
                        else dp[x][y1][y2] = grid[x][y1] + grid[x][y2];
                    }
                    else{
                        int maxCherries = 0;
                        for(int i = 0; i < 3; i++){
                            for(int j = 0; j < 3; j++){
                                int xo = x + dx[i], dy1 = y1 + dy[i], dy2 = y2 + dy[j];
                                if(isValid(xo, dy1, dy2)){
                                    maxCherries = max(maxCherries, dp[xo][dy1][dy2]);
                                }
                            }
                        }
                        maxCherries += grid[x][y1];
                        if(y1 != y2) maxCherries += grid[x][y2];
                        dp[x][y1][y2] = maxCherries;
                    }
                }
            }
        }
        return dp[0][0][cols - 1];
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int dx[3] = {1,1,1};
    int dy[3] = {-1,0,1};
    bool isValid(int x, int y1, int y2){
        if(x < n && y1 >= 0 && y2 >= 0 && y1 < m && y2 < m) return true;
        return false;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(cols, vector<int>(cols, 0));
        for(int x = n - 1; x >= 0; x--){
            vector<vector<int>> currdp(cols, vector<int>(cols, 0));
            for(int y1 = 0; y1 < m; y1++){
                for(int y2 = 0; y2 < m; y2++){
                    if(x == n - 1){
                        if(y1 == y2) currdp[y1][y2] = grid[x][y1];
                        else currdp[y1][y2] = grid[x][y1] + grid[x][y2];
                    }
                    else{
                        int maxCherries = 0;
                        for(int i = 0; i < 3; i++){
                            for(int j = 0; j < 3; j++){
                                int xo = x + dx[i], dy1 = y1 + dy[i], dy2 = y2 + dy[j];
                                if(isValid(xo, dy1, dy2)){
                                    maxCherries = max(maxCherries, dp[dy1][dy2]);
                                }
                            }
                        }
                        maxCherries += grid[x][y1];
                        if(y1 != y2) maxCherries += grid[x][y2];
                        currdp[y1][y2] = maxCherries;
                    }
                }
            }
            dp = currdp;
        }
        return dp[0][cols - 1];
    }
};
