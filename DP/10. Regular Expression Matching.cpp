//Top-Down
class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        
        if(i == 0 && j == 0){
            return true;
        }
        if(j == 0){
            return false;
        }
        if(i == 0){
            if(p[j - 1] == '*'){
                return solve(i, j - 2, s, p, dp);
            }
            else{
                return false;
            }
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[j - 1] == '*'){
            bool flag = solve(i, j - 2, s, p, dp);
            if(s[i - 1] == p[j - 2] || p[j - 2] == '.'){
                flag |= solve(i - 1, j, s, p, dp);
            }
            return dp[i][j] = flag;
        }
        if(s[i - 1] == p[j - 1] || p[j - 1] == '.'){
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        
        int len1 = s.size(), len2 = p.size();
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        
        return solve(len1, len2, s, p, dp);
    }
};

//Bottom-Up
class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.size(), m = p.size();
        
        int dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    if(p[j-1] == '*'){
                        dp[i][j] = dp[i][j-2];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else if(j == 0){
                    dp[i][j] = 0;
                }
                else{
                    
                    if(p[j-1] == '*'){
                        dp[i][j] = dp[i][j-2];
                        if(s[i-1] == p[j-2] || p[j-2] == '.'){
                            dp[i][j] = dp[i][j] || dp[i-1][j];
                        }
                    }
                    else if(p[j-1] == '.'){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(s[i-1] == p[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[n][m];
    }
};
