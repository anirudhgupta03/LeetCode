//Top-Down
//TC: O(len1*len2)
//SC: O(len1*len2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind1, int ind2, string &s1, string &s2, vector<int> &prefix1, vector<int> &prefix2, vector<vector<int>> &dp){
        
        if(ind1 == 0 && ind2 == 0){
            return 0;
        }
        if(ind1 == 0){
            return prefix2[ind2 - 1];
        }
        if(ind2 == 0){
            return prefix1[ind1 - 1];
        }
        
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(s1[ind1 - 1] == s2[ind2 - 1]){
            return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, s1, s2, prefix1, prefix2, dp);
        }
        else{
            return dp[ind1][ind2] = min(solve(ind1 - 1, ind2, s1, s2, prefix1, prefix2, dp) + s1[ind1 - 1], solve(ind1, ind2 - 1, s1, s2, prefix1, prefix2, dp) + s2[ind2 - 1]);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        
        int len1 = s1.size(), len2 = s2.size();
        
        vector<int> prefix1(len1), prefix2(len2);
        prefix1[0] = s1[0];
        for(int i = 1; i < len1; i++){
            prefix1[i] = prefix1[i - 1] + s1[i];
        }
        
        prefix2[0] = s2[0];
        for(int i = 1; i < len2; i++){
            prefix2[i] = prefix2[i - 1] + s2[i];
        }
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        return solve(len1, len2, s1, s2, prefix1, prefix2, dp);
    }
};

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len1*len2)
//Ref: https://www.youtube.com/watch?v=GPePWKCEy24
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int len1 = s1.size(), len2 = s2.size();
        
        int dp[len1 + 1][len2 + 1];
        
        dp[0][0] = 0;
        
        for(int j = 1; j <= len2; j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];    
        }
        
        for(int i = 1; i <= len1; i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j] + s1[i-1],dp[i][j-1] + s2[j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len2)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int len1 = s1.size(), len2 = s2.size();
        
        vector<int> pre(len2 + 1), curr(len2 + 1);
        pre[0] = 0;
        for(int i = 1; i <= len2; i++){
            pre[i] = pre[i - 1] + s2[i - 1];
        }
        
        for(int i = 1; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(j == 0){
                    curr[j] = pre[j] + s1[i - 1];
                }
                else if(s1[i - 1] == s2[j - 1]){
                    curr[j] = pre[j - 1];
                }
                else{
                    curr[j] = min(pre[j] + s1[i - 1], curr[j - 1] + s2[j - 1]);
                }
            }
            pre = curr;
        }
        return pre[len2];
    }
};
