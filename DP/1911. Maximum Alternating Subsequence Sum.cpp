//Top-Down
//TC: O(2*n)
//SC: O(2*n) + Auxilliary Stack Space
class Solution {
public:
    #define ll long long
    ll solve(int ind, int even, vector<int> &nums, vector<vector<ll>> &dp){
        
        if(ind == nums.size()){
            return 0;
        }
        
        if(dp[ind][even] != -1){
            return dp[ind][even];
        }
        ll maxSum = INT_MIN;
        
        if(even){
            return dp[ind][even] = max(solve(ind + 1, 0, nums, dp) + nums[ind], solve(ind + 1, 1, nums, dp));
        }
        else{
            return dp[ind][even] = max(solve(ind + 1, 1, nums, dp) - nums[ind], solve(ind + 1, 0, nums, dp));
        }
    }
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(2,-1));
        return solve(0, 1, nums, dp);
    }
};

//Bottom-Up
//TC: O(2*n)
//SC: O(2*n)
class Solution {
public:
    #define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2));
        
        for(int ind = n; ind >= 0; ind--){
            for(int even = 0; even <= 1; even++){
                 if(ind == nums.size()){
                    dp[ind][even] = 0;
                 }
                 else{
                    if(even){
                        dp[ind][even] = max(dp[ind + 1][0] + nums[ind], dp[ind + 1][1]);
                    }
                    else{
                        dp[ind][even] = max(dp[ind + 1][1] - nums[ind], dp[ind + 1][0]);
                    }
                 }
            }
        }
        return dp[0][1];
    }
};

//Bottom-Up
//TC: O(2*n)
//SC: O(1)
class Solution {
public:
    #define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<ll> pre(2, 0), curr(2);
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int even = 0; even <= 1; even++){
                 if(even){
                    curr[even] = max(pre[0] + nums[ind], pre[1]);
                 }
                 else{
                    curr[even] = max(pre[1] - nums[ind], pre[0]);
                 }
            }
            pre = curr;
        }
        return pre[1];
    }
};
