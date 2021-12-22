//Expert Problem
class Solution {
public:
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int max = INT_MIN;
        
        for(int k = i; k <= j - 1; k++){
            
            int temp1;
            if(dp[i][k] != -1) temp1 = dp[i][k];
            else               temp1 = solve(nums, i, k, dp);
            
            int temp2;
            if(dp[k+1][j] != -1) temp2 = dp[k+1][j];
            else                 temp2 = solve(nums, k + 1, j, dp);
            
            int tempans = temp1 + temp2 + nums[i-1]*nums[k]*nums[j];
            if(tempans > max){
                max = tempans;
            }
        }
        return dp[i][j] = max;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        return solve(nums, 1, nums.size() - 1,dp);
    }
};
