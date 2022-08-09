//Top-Down
//TC: O(n*sum)
//SC: O(n*sum) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp){
        
        if(sum == 0) return true;
        if(ind == nums.size()) return false;
        
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }
        
        int take, nottake;
        if(nums[ind] <= sum){
            take = solve(ind + 1, sum - nums[ind], nums, dp);
            if(take) return dp[ind][sum] = 1;
        }
        nottake = solve(ind + 1, sum, nums, dp);
        return dp[ind][sum] = nottake;
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        
        for(auto &x: nums){
            sum += x;
        }
        if(sum % 2 != 0){
            return false;
        }  
        sum /= 2;
       
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(0, sum, nums, dp);
    }
};

//Bottom-Up
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

//Bottom-Up
//TC: O(n*sum)
//SC: O(sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        
        for(auto &x: nums){
            sum += x;
        }
        if(sum % 2 != 0){
            return false;
        }
        
        sum /= 2;
        
        vector<bool> pre(sum + 1, false), curr(sum + 1);
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(j == 0){
                    curr[j] = true;
                }
                else if(nums[i - 1] <= j){
                    curr[j] = pre[j - nums[i - 1]] || pre[j];
                }
                else{
                    curr[j] = pre[j];
                }
            }
            pre = curr;
        }
        return pre[sum];
    }
};
