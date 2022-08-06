//Top-Down
//TC: O(len1*len2)
//SC: O(len1*len2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        
        if(i == 0 && j == 0){
            return 1;
        } 
        if(j == 0){
            return 0;
        }
        if(i == 0){
            if(p[j - 1] == '*'){
                return solve(i, j - 1, s, p, dp);
            }
            else{
                return 0;
            }
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        if(p[j - 1] == '*'){
            return dp[i][j] = solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        
        int len1 = s.size(), len2 = p.size();
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        
        return solve(len1, len2, s, p, dp);
    }
};

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len1*len2)
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
                        dp[i][j] = dp[i][j-1];
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
                        dp[i][j] = dp[i][j-1] || dp[i-1][j];      //Imp Step
                    }
                    else if(p[j-1] == '?' || s[i-1] == p[j-1]){
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

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len2)
class Solution {
public:
    bool isMatch(string s, string p) {
        
        int len1 = s.size(), len2 = p.size();
        
        vector<bool> dp(len2 + 1);
        dp[0] = true;
        
        for(int j = 1; j <= len2; j++){
            if(p[j - 1] == '*'){
                dp[j] = dp[j - 1];
            }
            else{
                dp[j] = false;
            }
        }
        
        for(int i = 1; i <= len1; i++){
            vector<bool> tdp(len2 + 1);
            for(int j = 0; j <= len2; j++){
                if(j == 0){
                    tdp[j] = false;
                }
                else{
                    if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                        tdp[j] = dp[j - 1];
                    }
                    else if(p[j - 1] == '*'){
                        tdp[j] = tdp[j - 1] || dp[j];
                    }
                    else{
                        tdp[j] = false;
                    }
                }
            }
            dp = tdp;
        }
        return dp[len2];
    }
};
