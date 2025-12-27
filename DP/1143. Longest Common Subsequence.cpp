//Top-Down
//TC: O(len1*len2)
//SC: O(len1*len2) + Auxilliary Stack Space O(len1 + len2)
class Solution {
public:
    int solve(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
        
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(text1[ind1 - 1] == text2[ind2 - 1]){
            return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, text1, text2, dp);
        }
        return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, text1, text2, dp), solve(ind1, ind2 - 1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int len1 = text1.size(), len2 = text2.size();
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        
        return solve(len1, len2, text1, text2, dp);
    }
};

//Bottom-Up
//TC: O(l1*l2)
//SC: O(l1*l2)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int l1 = text1.length();
        int l2 = text2.length();
        
        int dp[l1+1][l2+1];
        
        for(int i = 0; i < l1 + 1; i++){
            for(int j = 0; j < l2 + 1; j++){
                dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < l1 + 1; i++){
            for(int j = 1; j < l2 + 1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[l1][l2];
    }
};

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len2)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int len1 = text1.size(), len2 = text2.size();
        
        vector<int> pre(len2 + 1, 0), curr(len2 + 1);
        
        for(int i = 1; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(j == 0){
                    curr[j] = 0;
                }
                else if(text1[i - 1] == text2[j - 1]){
                    curr[j] = 1 + pre[j - 1];
                }
                else{
                    curr[j] = max(pre[j], curr[j - 1]);
                }
            }
            pre = curr;
        }
        return pre[len2];
    }
};
