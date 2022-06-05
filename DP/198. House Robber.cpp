//Method - 1
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1){
            return nums[0];
        }
        
        int dp[n];
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        int max1 = dp[0];
        int max2 = max(dp[0],dp[1]);
        
        for(int i = 2; i < n; i++){
            
            if(i % 2 == 0){
                dp[i] = max1 + nums[i];
                max1 = max(max2,dp[i]);
            }
            else{
                dp[i] = max2 + nums[i];
                max2 = max(max1,dp[i]);
            }
        }
        return max(dp[n-1],dp[n-2]);
    }
};

//Method - 2
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        vector<int> dp(n);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[n - 1];
    }
};

//Method - 3
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
