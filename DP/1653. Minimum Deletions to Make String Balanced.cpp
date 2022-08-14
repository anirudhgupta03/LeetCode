//Top-Down
//TC: O(n)
//SC: O(n) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, string &s, vector<int> &cnta, vector<int> &dp){
        
        if(ind == s.size()){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        if(s[ind] == 'a'){
            return dp[ind] = solve(ind + 1, s, cnta, dp);
        }
        else{
            return dp[ind] = min(1 + solve(ind + 1, s, cnta, dp), cnta[ind]);
        }
    }
    int minimumDeletions(string s) {
        
        int n = s.size();
        vector<int> cnta(n, 0);
        
        if(s[n - 1] == 'a') cnta[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            cnta[i] = cnta[i + 1];
            if(s[i] == 'a') cnta[i]++;
        }
        
        vector<int> dp(n, -1);
        return solve(0, s, cnta, dp);
    }
};

//Bottom-Up
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        vector<int> cnta(n, 0);
        
        if(s[n - 1] == 'a') cnta[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            cnta[i] = cnta[i + 1];
            if(s[i] == 'a') cnta[i]++;
        }
        
        vector<int> dp(n + 1);
        
        for(int ind = n; ind >= 0; ind--){
            if(ind == s.size()){
                dp[ind] = 0;
            }
            else if(s[ind] == 'a'){
                dp[ind] = dp[ind + 1];
            }
            else{
                dp[ind] = min(1 + dp[ind + 1], cnta[ind]);
            }
        }
        return dp[0];
    }
};

//Bottom-Up
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        
        vector<int> dp(n + 1);
        int cnta = 0;
        
        for(int ind = n; ind >= 0; ind--){
            if(ind == s.size()){
                dp[ind] = 0;
            }
            else if(s[ind] == 'a'){
                dp[ind] = dp[ind + 1];
                cnta++;
            }
            else{
                dp[ind] = min(1 + dp[ind + 1], cnta);
            }
        }
        return dp[0];
    }
};

//Bottom-Up
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        
        int cnta = 0, curr, pre = 0;
        
        for(int ind = n - 1; ind >= 0; ind--){
            if(s[ind] == 'a'){
                curr = pre;
                cnta++;
            }
            else{
                curr = min(1 + pre, cnta);
            }
            pre = curr;
        }
        return pre;
    }
};
