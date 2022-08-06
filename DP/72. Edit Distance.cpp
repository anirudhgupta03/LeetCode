//Top-Down
//TC: O(len1*len2)
//SC: O(len1*len2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        
        if(i == 0){
            return j;
        }
        if(j == 0){
            return i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i - 1] == word2[j - 1]){
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        }
        return dp[i][j] = 1 + min({solve(i - 1, j - 1, word1, word2, dp), solve(i - 1, j, word1, word2, dp), solve(i, j - 1, word1, word2, dp)});
    }
    int minDistance(string word1, string word2) {
        
        int len1 = word1.size(), len2 = word2.size();
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        
        return solve(len1, len2, word1, word2, dp);
    }
};

//Bottom-Up
//TC: O(len1*len2)
//SC: O(len1*len2)
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int l1 = word1.size(), l2 = word2.size();
        
        int dp[l1+1][l2+1];
        
        for(int i = 0; i <= l1; i++){
            for(int j = 0; j <= l2; j++){
                
                if(i == 0){
                    dp[i][j] = j;
                }
                else if(j == 0){
                    dp[i][j] = i;
                }
                else if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;
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
    int minDistance(string word1, string word2) {
        
        int len1 = word1.size(), len2 = word2.size();
        
        vector<int> pre(len2 + 1, 0);
        
        for(int j = 0; j <= len2; j++){
            pre[j] = j;
        }
        
        for(int i = 1; i <= len1; i++){
            vector<int> curr(len2 + 1);
            for(int j = 0; j <= len2; j++){
                if(j == 0){
                    curr[j] = i;
                }
                else if(word1[i - 1] == word2[j - 1]){
                    curr[j] = pre[j - 1];
                }
                else{
                    curr[j] = min({pre[j - 1], pre[j], curr[j - 1]}) + 1;
                }
            }
            pre = curr;
        }
        return pre[len2];
    }
};
