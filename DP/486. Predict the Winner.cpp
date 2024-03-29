//Ref: https://www.youtube.com/watch?v=ww4V7vRIzSk
//Using Recursion
class Solution {
public:
    int solve(int lo, int hi, vector<int> &nums){
        
        if(lo > hi){
            return 0;
        }
        
        if(lo == hi){
            return nums[lo];
        }
        
        int sum1 = solve(lo + 2, hi, nums) + nums[lo];
        int sum2 = solve(lo + 1, hi - 1, nums) + nums[hi];
        int sum3 = solve(lo, hi - 2, nums) + nums[hi];
        int sum4 = solve(lo + 1, hi - 1, nums) + nums[lo];
        
        int result = max(min(sum2,sum3),min(sum1,sum4));
        return result;
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        int temp = solve(0, nums.size() - 1, nums);
        
        cout << temp << endl;
        
        if(temp >= sum - temp){
            return true;
        }
        return false;
    }
};

//Method - 2
//Using Recursion + Memoization
class Solution {
public:
    int solve(int lo, int hi, vector<int> &nums, vector<vector<int>> &dp){
        
        if(lo > hi){
            return 0;
        }

        if(dp[lo][hi] != -1){
            return dp[lo][hi];
        }
        
        int val1 = solve(lo + 2, hi, nums, dp) + nums[lo];
        int val2 = solve(lo + 1, hi - 1, nums, dp) + nums[lo];
        
        int val3 = solve(lo, hi - 2, nums, dp) + nums[hi];
        int val4 = solve(lo + 1, hi - 1, nums, dp) + nums[hi];
        
        return dp[lo][hi] = max(min(val1, val2), min(val3, val4));
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        
        for(int x: nums){
            sum += x;
        }
        
        int lo = 0, hi = n - 1;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int maxScore1 = solve(0, hi, nums, dp);
        int maxScore2 = sum - maxScore1;
        
        if(maxScore1 >= maxScore2){
            return true;
        }
        return false;
    }
};
