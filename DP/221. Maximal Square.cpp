class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int maxLen = 0;
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(j == n - 1 || i == m - 1){
                    if(matrix[i][j] == '1'){
                        dp[i][j] = 1;
                        maxLen = 1;
                    }
                }
            }
        }
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]}) + 1;
                }
                maxLen = max(maxLen,dp[i][j]);
            }
        }
        return maxLen*maxLen;
    }
};
