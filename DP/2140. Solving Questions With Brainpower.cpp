//Top-Down
//TC: O(n)
//SC: O(n) + Auxilliary Stack Space
class Solution {
public:
    #define ll long long
    ll solve(int ind, vector<vector<int>> &questions, vector<ll> &dp){
        
        if(ind >= questions.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        return dp[ind] = max(solve(ind + questions[ind][1] + 1, questions, dp) + questions[ind][0], solve(ind + 1, questions, dp));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        vector<ll> dp(n, -1);
        return solve(0, questions, dp);
    }
};

//Bottom-Up
//TC: O(n)
//SC: O(n)
class Solution {
public:
    #define ll long long
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        vector<ll> dp(n + 1, 0);
        
        for(int ind = n - 1; ind >= 0; ind--){
            dp[ind] = dp[ind + 1];
            if(ind + questions[ind][1] + 1 <= n){
                dp[ind] = max(dp[ind], dp[ind + questions[ind][1] + 1] + questions[ind][0]);
            }
            else{
                dp[ind] = max(dp[ind], (ll)questions[ind][0]);
            }
        }
        return dp[0];
    }
};
