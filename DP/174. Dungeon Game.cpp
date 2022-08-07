//Method - 1
class Solution {
public:
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    int solve(int x, int y, vector<vector<int>> &dp, vector<vector<int>> &vis, vector<vector<int>> &dungeon, int m, int n){
        
        if(x == m - 1 && y == n - 1){
            return 1;
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int minhp = INT_MAX;
        
        for(int i = 0; i < 2; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo < m && xo >= 0 && yo < n && yo >= 0){
                
                if(vis[xo][yo] == 0){
                    if(dungeon[xo][yo] <= 0){
                       vis[xo][yo] = 1;
                       int temp = solve(xo, yo, dp, vis, dungeon, m, n);
                       if(temp != INT_MAX){
                            minhp = min(minhp, abs(dungeon[xo][yo]) + temp);
                       } 
                       vis[xo][yo] = 0;
                    }
                    else{
                        vis[xo][yo] = 1;
                        int temp = solve(xo, yo, dp, vis, dungeon, m, n);
                        if(temp != INT_MAX){
                            minhp = min(minhp, max(temp - dungeon[xo][yo],1));
                        }
                        vis[xo][yo] = 0;
                    }
                }
                
            }
        }
        return dp[x][y] = minhp;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size(), n = dungeon[0].size();
        int minhp = INT_MAX;
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        int temp = solve(0,0,dp,vis,dungeon,m,n);
        
        if(dungeon[0][0] < 0){
            return abs(dungeon[0][0]) + temp;
        }
        else{
            return max(temp - dungeon[0][0],1);
        }
    }
};

//Method - 2
//Optimal Method
class Solution {
public:
    int dx[2] = {0,1};
    int dy[2] = {1,0};
    
    int solve(int x, int y, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &dungeon){
        
        if(x == m - 1 && y == n - 1){
            if(dungeon[x][y] < 0){
                return dp[x][y] = 1 - dungeon[x][y];
            }
            else{
                return dp[x][y] = 1;
            }
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int ans = INT_MAX;
        
        for(int i = 0; i < 2; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo < m && yo < n){
                int temp = solve(xo, yo, m, n, dp, dungeon);
                if(dungeon[x][y] >= 0){
                    temp = max(1, temp - dungeon[x][y]);
                }
                else{
                    temp -= dungeon[x][y];
                }
                ans = min(ans, temp);
            }
        }
        return dp[x][y] = ans;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size(), n = dungeon[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, - 1));
        
        return solve(0, 0, m, n, dp, dungeon);
    }
};

//Method - 3
class Solution {
public:
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    int solve(int x, int y, int m, int n, vector<vector<int>> &dungeon, vector<vector<int>> &dp){
        
        if(x == m - 1 && y == n - 1){
            if(dungeon[x][y] >= 0){
                return 1;
            }
            else{
                return 1 - dungeon[x][y];
            }
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        int minHealth = INT_MAX;
        
        for(int i = 0; i < 2; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo < m && yo < n){
                int temp = solve(xo, yo, m, n, dungeon, dp);
                if(temp != INT_MAX){
                    if(temp - dungeon[x][y] > 0){
                        minHealth = min(minHealth, temp - dungeon[x][y]);
                    }
                    else{
                        minHealth = min(minHealth, 1);
                    }
                }
            }
        }
        return dp[x][y] = minHealth;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size(), n = dungeon[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solve(0, 0, m, n, dungeon, dp);
    }
};
