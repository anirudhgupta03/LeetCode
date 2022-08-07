class Solution {
public:
    int solve(int i, int n, vector<int> &nums, vector<int> &dp){
        
        if(i == n){
            return 1;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        if(i + 1 < n && nums[i + 1] == nums[i]){
            bool flag = solve(i + 2, n, nums, dp);
            if(flag) return dp[i] = 1;
        }
        if(i + 1 < n && i + 2 < n && nums[i + 1] == nums[i] && nums[i + 2] == nums[i]){
            bool flag = solve(i + 3, n, nums, dp);
            if(flag) return dp[i] = 1;
        }
        if(i + 1 < n && i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1){
            bool flag = solve(i + 3, n, nums, dp);
            if(flag) return dp[i] = 1;
        }
        return dp[i] = 0;
    }
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, -1);
        return solve(0, n, nums, dp);
    }
};
