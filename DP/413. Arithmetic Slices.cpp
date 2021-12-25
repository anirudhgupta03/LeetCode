class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1 || n == 2){
            return 0;
        }
        
        int dp[n];
        dp[0] = 0;
        dp[1] = 0;
        
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = 0;
            }
            ans += dp[i];
        }
        return ans;
    }
};
