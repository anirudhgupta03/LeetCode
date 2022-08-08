//Ref: https://www.youtube.com/watch?v=iJIAPtd9Z9s
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() <= 1){
            return nums.size();
        }
        
        int up = 1, down = 1;
        
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] < nums[i+1]){
                up = down + 1;
            }
            else if(nums[i] > nums[i+1]){
                down = up + 1;
            }
        }
        return max(down, up);
    }
};

//Top-Down
//TC: O(2*n*n)
//SC: O(2*n*n) + Auxilliary Stack Space
class Solution {
public:
    int solve(int preDiff, int preInd, int currInd, vector<int> &nums, vector<vector<vector<int>>> &dp){
        
        if(currInd == nums.size()){
            return 1;
        }
        
        if(dp[preDiff][preInd][currInd] != -1){
            return dp[preDiff][preInd][currInd];
        }
        int ans = 0;
        
        if(preDiff == 0){   //-ve
            if(nums[currInd] - nums[preInd] > 0){
                ans = max(ans, solve(1, currInd, currInd + 1, nums, dp) + 1);
            }
            ans = max(ans, solve(0, preInd, currInd + 1, nums, dp));
        }
        else if(preDiff == 1){  //+ve
            if(nums[currInd] - nums[preInd] < 0){
                ans = max(ans, solve(0, currInd, currInd + 1, nums, dp) + 1);
            }
            ans = max(ans, solve(1, preInd, currInd + 1, nums, dp));
        }
        return dp[preDiff][preInd][currInd] = ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return max(solve(0, 0, 1, nums, dp), solve(1, 0, 1, nums, dp));
    }
};
