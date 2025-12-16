//Recursion + Memoization
class Solution {
public:
    int maxRob(int ind, vector<int>& nums, vector<int>& dp){
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(maxRob(ind + 2, nums, dp) + nums[ind], maxRob(ind + 1, nums, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxRob(0, nums, dp);
    }
};

//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int val1 = nums[0];
        int val2 = max(nums[0], nums[1]);
        vector<int> dp(n);
        dp[0] = val1;
        dp[1] = val2;
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

//Tabluation + Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int val1 = nums[0];
        int val2 = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            int val3 = max(val2, val1 + nums[i]);
            val1 = val2;
            val2 = val3;
        }
        return val2;
    }
};
