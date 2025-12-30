class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
      
        vector<pair<int,int>> dp(n, {1,1});     //len, count
        int maxLen = 1, count = 1;
      
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j].first + 1 > dp[i].first){
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    }
                    else if(dp[j].first + 1 == dp[i].first){
                        dp[i] = {dp[i].first, dp[i].second + dp[j].second};
                    }
                }
            }
            if(dp[i].first > maxLen){
                maxLen = dp[i].first;
                count = dp[i].second;
            }
            else if(dp[i].first == maxLen){
                count += dp[i].second;
            }
        }
        return count;
    }
};
