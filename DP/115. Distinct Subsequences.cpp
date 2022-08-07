//Top-Down
//TC: O(len1*len2)
//SC: O(len1*len2) + Auxilliary Stack Space
class Solution {
public:
    #define ld long double
    int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
        
        if(ind2 == t.size()){
            return 1;
        }
        if(ind1 == s.size()){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        int count = 0;
        if(s[ind1] == t[ind2]){
            count += solve(ind1 + 1, ind2 + 1, s, t, dp) + solve(ind1 + 1, ind2, s, t, dp);
        }
        else{
            count += solve(ind1 + 1, ind2, s, t, dp);
        }
        return dp[ind1][ind2] = count;
    }
    int numDistinct(string s, string t) {
        
        int len1 = s.size(), len2 = t.size();
        
        vector<vector<ld>> dp(len1, vector<ld>(len2, -1));
        
        return solve(0, 0, s, t, dp);
    }
};

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len1*len2)
class Solution {
public:
    #define ld long double
    int numDistinct(string s, string t) {
        
        int len1 = s.size(), len2 = t.size();
        
        vector<vector<ld>> dp(len1 + 1, vector<ld>(len2 + 1));
        
        for(int ind1 = len1; ind1 >= 0; ind1--){
            for(int ind2 = len2; ind2 >= 0; ind2--){
                if(ind2 == len2){
                    dp[ind1][ind2] = 1;
                }
                else if(ind1 == len1){
                    dp[ind1][ind2] = 0;
                }
                else if(s[ind1] == t[ind2]){
                    dp[ind1][ind2] = dp[ind1 + 1][ind2 + 1] + dp[ind1 + 1][ind2];
                }
                else{
                    dp[ind1][ind2] = dp[ind1 + 1][ind2];
                }
            }
        }
        return dp[0][0];
    }
};

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len2)
class Solution {
public:
    #define ld long double
    int numDistinct(string s, string t) {
        
        int len1 = s.size(), len2 = t.size();
        
        vector<ld> pre(len2 + 1, 0), curr(len2 + 1);
        pre[len2] = 1;
        
        for(int ind1 = len1 - 1; ind1 >= 0; ind1--){
            for(int ind2 = len2; ind2 >= 0; ind2--){
                if(ind2 == len2){
                    curr[ind2] = 1;
                }
                else if(s[ind1] == t[ind2]){
                    curr[ind2] = pre[ind2 + 1] + pre[ind2];
                }
                else{
                    curr[ind2] = pre[ind2];
                }
            }
            pre = curr;
        }
        return pre[0];
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
