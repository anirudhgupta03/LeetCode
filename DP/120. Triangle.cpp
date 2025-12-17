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
        for(int j = 0; j < n; j++) dp[n - 1][j] = triangle[n - 1][j];
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for(int j = 0; j < n; j++) dp[j] = triangle[n - 1][j];
        for(int i = n - 2; i >= 0; i--){
            vector<int> currdp(n, 0);
            for(int j = i; j >= 0; j--){
                currdp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
            dp = currdp;
        }
        return dp[0];
    }
};
