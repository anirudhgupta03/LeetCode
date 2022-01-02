class Solution {
public:
    #define ll long long
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    ll solve(int x, int y, int maxMove, int m, int n, vector<vector<vector<ll>>> &dp, int mod){
        
        if(x < 0 || y < 0 || x >= m || y >= n){
            return 1;
        }
        if(maxMove == 0){
            return 0;
        }
        if(dp[x][y][maxMove] != -1){
            return dp[x][y][maxMove];
        }
        
        ll count = 0;
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            count = (count + solve(xo, yo, maxMove - 1, m, n, dp,mod))%mod;
        }
        return dp[x][y][maxMove] = count%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        ll count = 0;
        int mod = 1e9 + 7;
        
        vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(n + 1, vector<ll>(maxMove + 1, - 1)));
        
        count = solve(startRow,startColumn,maxMove,m,n,dp,mod);
        
        return count%mod;
    }
};
