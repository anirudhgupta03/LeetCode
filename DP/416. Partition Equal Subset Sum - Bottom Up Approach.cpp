//TC: O(n*sum)
//SC: O(n*sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        
        for(int x: nums){
            sum += x;
        }
        
        if(sum % 2 != 0){
            return false;
        }
        sum /= 2;
        int n = nums.size();
        
        bool dp[n + 1][sum + 1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                
                if(j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0){
                    dp[i][j] = false;
                }
                else if(nums[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
