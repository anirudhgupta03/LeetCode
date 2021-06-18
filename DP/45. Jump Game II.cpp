class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        int dp[n];
        
        memset(dp,0,sizeof(dp));
        
        int cov = 0;
        
        for(int i = 0; i < n - 1; i++){
            
            for(int j = cov + 1; j <= i + nums[i]; j++){
                if(j < n)
                    dp[j] = dp[i] + 1;
                else
                    break;
            }
            cov = max(cov,nums[i]+i);
        }
        return dp[n-1];
    }
};
