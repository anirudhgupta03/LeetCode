//Recursion + Memoization
//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1127236/C%2B%2B-Recursive-Memoization
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp, int p,int n, int m, vector<int>& nums, vector<int>& mult){
        
        if(p == m){
            return 0;
        }
        
        if(i > j){
            return 0;
        }
        
        if(dp[i][p] != -1){
            return dp[i][p];
        }
        
        return dp[i][p] = max(nums[i]*mult[p] + solve(i+1,j,dp,p+1,n,m,nums,mult), nums[j]*mult[p] + solve(i,j-1,dp,p+1,n,m,nums,mult));
    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        
        int n = nums.size(), m = mult.size();
        
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        
        return solve(0,n-1,dp,0,n,m,nums,mult);
        
    }
};
