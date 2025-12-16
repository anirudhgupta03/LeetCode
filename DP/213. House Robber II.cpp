//Ref: https://www.youtube.com/watch?v=3WaxQMELSkw
class Solution {
public:
    int solve(int lo, int hi, vector<int> &nums){
        
        int val1 = nums[lo];
        int val2 = max(nums[lo], nums[lo + 1]);
        
        for(int i = lo + 2; i <= hi; i++){
            int val3 = max(val1 + nums[i], val2);
            val1 = val2;
            val2 = val3;
        }
        return val2;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        int ans1 = solve(0, n - 2, nums);
        int ans2 = solve(1, n - 1, nums);
        return max(ans1, ans2);
    }
};
