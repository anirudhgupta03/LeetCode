//Method - 1
//Top-Down
class Solution {
public:
    bool isPalindrome(string &s){
        int lo = 0, hi = s.size() - 1;
        while(lo < hi){
            if(s[lo] != s[hi]) return false;
            lo++;
            hi--;
        }
        return true;
    }
    int solve(int ind, string &s, vector<int> &dp){
        
        if(ind == s.size()){
            return -1;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int minCut = INT_MAX;
        string temp;
        for(int i = ind; i < s.size(); i++){
            temp.push_back(s[i]);
            if(isPalindrome(temp)){
                minCut = min(minCut, 1 + solve(i + 1, s, dp));
            }
        }
        return dp[ind] = minCut;
    }
    int minCut(string s) {
        
        vector<int> dp(s.size(), - 1);
        
        return solve(0, s, dp);
    }
};

//Method - 2
//Top-Down
//Optimal Approach
class Solution {
public:
    int solve(int ind, string &s, vector<vector<bool>> &isPalindrome, vector<int> &dp){
        
        if(ind == s.size()){
            return -1;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int minCuts = INT_MAX;
        for(int i = ind; i < s.size(); i++){
            if(isPalindrome[ind][i]){
                minCuts = min(minCuts, 1 + solve(i + 1, s, isPalindrome, dp));
            }
        }
        return dp[ind] = minCuts;
    }
    int minCut(string s) {
        
        int len = s.size();
        
        vector<vector<bool>> isPalindrome(len, vector<bool>(len));
        
        for(int i = 0; i < len; i++){
            isPalindrome[i][i] = true;
        }
        
        for(int i = 0; i < len - 1; i++){
            if(s[i] == s[i + 1]){
                isPalindrome[i][i + 1] = true;
            }
        }
        
        for(int i = len - 3; i >= 0; i--){
            for(int j = i + 2; j < len; j++){
                if(s[i] == s[j] && isPalindrome[i + 1][j - 1]){
                    isPalindrome[i][j] = true;
                }
                else{
                    isPalindrome[i][j] = false;
                }
            }
        }
        vector<int> dp(len, -1);
        return solve(0, s, isPalindrome, dp);
    }
};

//Method - 3
//Bottom-Up
//TC: O(N*N)
//SC: O(N*N)
class Solution {
public:
    int minCut(string s) {
        int len = s.length();

        vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));

        for(int i = 0; i < len; i++){
            isPalindrome[i][i] = true;
            if(i < len - 1 && s[i] == s[i + 1]){
                isPalindrome[i][i + 1] = true;
            }
        }

        for(int i = len - 3; i >= 0; i--){
            for(int j = i + 2; j < len; j++){
                if(s[i] == s[j] && isPalindrome[i + 1][j - 1]){
                    isPalindrome[i][j] = true;
                }
            }
        }
        
        vector<int> dp(len + 1, -1);
        for(int i = len - 1; i >= 0; i--){
            int minCuts = INT_MAX;
            for(int k = i; k <= len - 1; k++){
                if(isPalindrome[i][k]){
                    minCuts = min(minCuts, 1 + dp[k + 1]);
                }
            }
            dp[i] = minCuts;
        }
        return dp[0];
    }
};
