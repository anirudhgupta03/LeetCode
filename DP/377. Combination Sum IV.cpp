class Solution {
public:
    int solve(int sum, vector<int> &nums, int target, vector<int> &dp){
        
        if(target == sum){
            return 1;
        }
        
        if(dp[sum] != -1){
            return dp[sum];
        }
        
        int count = 0;
      
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= target){
                count += solve(nums[i] + sum, nums, target, dp);
            }
        }
        return dp[sum] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        int count = 0, sum = 0;
        
        vector<int> dp(target + 1, -1);
        
        return solve(sum, nums, target, dp);
    }
};
