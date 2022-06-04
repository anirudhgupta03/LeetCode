//Method - 1
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
//Optimal Approach
class Solution {
public:
    int dp[2001];
    int solve(int ind, string &A, vector<vector<int>> &isPalindrome){
        if(ind == A.size()){
            return -1;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int minCuts = INT_MAX;
        for(int i = ind; i < A.size(); i++){
            if(isPalindrome[ind][i]){
                minCuts = min(minCuts, solve(i + 1, A, isPalindrome) + 1);
            }
        }
        return dp[ind] = minCuts;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        vector<vector<int>> isPalindrome(n, vector<int>(n,0));
        for(int i = 0; i < n; i++){
            isPalindrome[i][i] = 1; 
        }
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                isPalindrome[i][i + 1] = 1;
            }
        }
        for(int i = n - 3; i >= 0; i--){
            for(int j = i + 2; j < n; j++){
                if(s[i] == s[j]){
                    isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }
        return solve(0,s,isPalindrome);
    }
};
