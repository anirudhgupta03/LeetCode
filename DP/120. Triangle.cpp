//Recursion + Memoization
//TLE
class Solution {
public:
    int findMinimumTotal(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row == triangle.size() - 1) return triangle[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = min(findMinimumTotal(row + 1, col, triangle, dp), findMinimumTotal(row + 1, col + 1, triangle, dp)) + triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findMinimumTotal(0, 0, triangle, dp);
    }
};

//Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++){
            for(int j = 1; j < i; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        int minSum = INT_MAX;
        for(int j = 0; j < n; j++){
            minSum = min(minSum, dp[n - 1][j]);
        }
        return minSum;
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; i++){
            vector<int> currdp(n, 0);
            for(int j = 1; j < i; j++){
                currdp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
            currdp[0] = dp[0] + triangle[i][0];
            currdp[i] = dp[i - 1] + triangle[i][i];
            dp = currdp;
        }
        int minSum = INT_MAX;
        for(int j = 0; j < n; j++){
            minSum = min(minSum, dp[j]);
        }
        return minSum;
    }
};
