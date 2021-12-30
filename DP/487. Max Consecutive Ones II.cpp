//https://www.lintcode.com/problem/883/
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        vector<int> lr(n,0);

        if(nums[0] == 1) lr[0] = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] == 0) lr[i] = 0;
            else lr[i] = lr[i-1] + 1;
        }

        vector<int> rl(n,0);
        if(nums[n-1] == 1) rl[n - 1] = 1;

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] == 0) rl[i] = 0;
            else rl[i] = rl[i+1] + 1;
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                ans = max(ans, rl[1] + 1);
            }
            else if(i == n - 1){
                ans = max(ans, lr[n-2] + 1);
            }
            else{
                ans = max(ans, lr[i-1] + rl[i+1] + 1);
            }
        }
        return ans;
    }
};
