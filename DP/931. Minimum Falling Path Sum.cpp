//Recursion + Memoization
class Solution {
public:
    int dx[3] = {1, 1, 1};
    int dy[3] = {0, 1, -1};
    int findMinFallingPathSum(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(row == matrix.size() - 1) return matrix[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int minSum = INT_MAX;
        for(int i = 0; i < 3; i++){
            int rowo = row + dx[i], colo = col + dy[i];
            if(rowo < matrix.size() && colo < matrix[0].size() && colo >= 0){
                minSum = min(minSum, findMinFallingPathSum(rowo, colo, matrix, dp));
            }
        }
        return dp[row][col] = minSum + matrix[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int j = 0; j < matrix.size(); j++){
            minSum = min(minSum, findMinFallingPathSum(0, j, matrix, dp));
        }
        return minSum;
    }
};

//Tabulation
class Solution {
public:
    int dx[3] = {1, 1, 1};
    int dy[3] = {0, 1, -1};
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int j = 0; j < n; j++){
            dp[n - 1][j] = matrix[n - 1][j];
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int minSum = INT_MAX;
                for(int k = 0; k < 3; k++){
                    int rowo = i + dx[k], colo = j + dy[k];
                    if(rowo < n && colo >= 0 && colo < n){
                        minSum = min(minSum, dp[rowo][colo]);
                    }
                }
                dp[i][j] = minSum + matrix[i][j];
            }
        }
        for(int j = 0; j < n; j++){
            minSum = min(minSum, dp[0][j]);
        }
        return minSum;
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int dx[3] = {1, 1, 1};
    int dy[3] = {0, 1, -1};
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;
        
        vector<int> dp(n);
        for(int j = 0; j < n; j++){
            dp[j] = matrix[n - 1][j];
        }
        
        for(int i = n - 2; i >= 0; i--){
            vector<int> currdp(n);
            for(int j = 0; j < n; j++){
                int minSum = INT_MAX;
                for(int k = 0; k < 3; k++){
                    int rowo = i + dx[k], colo = j + dy[k];
                    if(rowo < n && colo >= 0 && colo < n){
                        minSum = min(minSum, dp[colo]);
                    }
                }
                currdp[j] = minSum + matrix[i][j];
            }
            dp = currdp;
        }
  
        for(int j = 0; j < n; j++){
            minSum = min(minSum, dp[j]);
        }
        return minSum;
    }
};
