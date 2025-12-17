//Recursion
class Solution {
public:
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    int findUniquePaths(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int count = 0;
        for(int dir = 0; dir < 2; dir++){
            int di = i + dx[dir], dj = j + dy[dir];
            if(di < m && dj < n){
                count += findUniquePaths(di, dj, m, n, dp);
            }
        }
        return dp[i][j] = count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findUniquePaths(0, 0, m, n, dp);
    }
};

//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    if(i - 1 >= 0) dp[i][j] += dp[i - 1][j];
                    if(j - 1 >= 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        for(int i = 0; i < m; i++){
            vector<int> currdp(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    currdp[j] = 1;
                }
                else{
                    if(i - 1 >= 0) currdp[j] += dp[j];
                    if(j - 1 >= 0) currdp[j] += currdp[j - 1];
                }
            }
            dp = currdp;
        }
        return dp[n - 1];
    }
};

//Mathematical
class Solution {
public:
    #define ll long long
    int uniquePaths(int m, int n) {
        m--;
        n--;
        ll paths = 1;
        for(int i = 1; i <= min(m,n); i++){
            paths *= (m + n - i + 1);
            paths /= i;
        }
        return paths;
    }
};
