class Solution {
public:
    #define mod 1000000007
    #define ll long long
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    ll dfs(int x, int y, vector<vector<int>> &grid, vector<vector<ll>> &dp){
        
        if(dp[x][y] != -1){
            return dp[x][y];
        } 
        
        ll res = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size() && grid[xo][yo] > grid[x][y]){
                res = (res + dfs(xo, yo, grid, dp))%mod;
            }
        }
        return dp[x][y] = res;
    }
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<ll>> dp(m, vector<ll>(n, - 1));
        
        ll ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = (ans + dfs(i, j, grid, dp))%mod;
            }
        }
        return ans;
    }
};
