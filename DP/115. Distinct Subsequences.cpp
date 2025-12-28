//Top-Down
//TC: O(len1*len2)
//SC: O(len1*len2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
        if(ind2 == -1) return 1;
        if(ind1 == -1) return 0;
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        int take = 0;
        if(s[ind1] == t[ind2]){
            take = solve(ind1 - 1, ind2 - 1, s, t, dp);
        }
        int notTake = solve(ind1 - 1, ind2, s, t, dp);
        return dp[ind1][ind2] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return solve(len1 - 1, len2 - 1, s, t, dp);
    }
};

//Bottom-Up
//Tabulation
//TC: O(len1*len2)
//SC: O(len1*len2)
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        vector<vector<double>> dp(len1 + 1, vector<double>(len2 + 1, 0));
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = 0;
                }
                else{
                    double take = 0;
                    if(s[i - 1] == t[j - 1]){
                        take = dp[i - 1][j - 1];
                    }
                    double notTake = dp[i - 1][j];
                    dp[i][j] = take + notTake;
                }
            }
        }
        return (int)dp[len1][len2];
    }
};

//Bottom-Up
//Tabulation + Space Optimization
//TC: O(len1*len2)
//SC: O(len2)
//2 DP Array
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        vector<double> prevDP(len2 + 1, 0);
        for(int i = 0; i <= len1; i++){
            vector<double> currDP(len2 + 1, 0);
            for(int j = 0; j <= len2; j++){
                if(j == 0){
                    currDP[j] = 1;
                }
                else if(i == 0){
                    currDP[j] = 0;
                }
                else{
                    double take = 0;
                    if(s[i - 1] == t[j - 1]){
                        take = prevDP[j - 1];
                    }
                    double notTake = prevDP[j];
                    currDP[j] = take + notTake;
                }
            }
            prevDP = currDP;
        }
        return (int)prevDP[len2];
    }
};

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len1*len2)
//Ref: https://www.youtube.com/watch?v=-RDzMJ33nx8
class Solution {
public:
    int numDistinct(string s, string t) {
        
        int len1 = s.size(), len2 = t.size();
        
        double dp[len1 + 1][len2 + 1];
        
        for(int j = 0; j <= len2; j++){
            dp[0][j] = 0;
        }
        for(int i = 0; i <= len1; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[len1][len2];
    }
};

//Bottom-Up
//Tabulation + Space Optimization
//TC: O(len1*len2)
//SC: O(len2)
//1 DP Array
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        vector<double> dp(len2 + 1, 0);
        for(int i = 0; i <= len1; i++){
            for(int j = len2; j >= 0; j--){
                if(j == 0){
                    dp[j] = 1;
                }
                else if(i == 0){
                    dp[j] = 0;
                }
                else{
                    double take = 0;
                    if(s[i - 1] == t[j - 1]){
                        take = dp[j - 1];
                    }
                    double notTake = dp[j];
                    dp[j] = take + notTake;
                }
            }
        }
        return (int)dp[len2];
    }
};
