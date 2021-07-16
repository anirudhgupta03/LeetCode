class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    int solve(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int maxlen = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && xo < matrix.size() && yo >= 0 && yo < matrix[0].size() && matrix[xo][yo] > matrix[x][y]){
                maxlen = max(maxlen, solve(xo,yo,matrix,dp) + 1);
            }
        }
        
        return dp[x][y] = maxlen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int lip = 1;
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                lip = max(lip,solve(i,j,matrix,dp));
            }
        }
        return lip;
    }
};
