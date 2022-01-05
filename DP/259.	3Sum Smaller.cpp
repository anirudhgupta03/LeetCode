//https://www.lintcode.com/problem/3sum-smaller/description
class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int solve(int ind, int sum, vector<int> &nums, int target, int count, map<pair<pair<int,int>,int>,int> &dp){

        if(count == 3){
            if(sum < target){
               return 1;
            }
            return 0;
        }
        if(dp.find({{ind,sum},count}) != dp.end()){
            return dp[{{ind,sum},count}];
        }
        int ans = 0;
        for(int i = ind; i <= nums.size() - 3 + count; i++){
            ans += solve(i + 1, sum + nums[i], nums, target, count + 1, dp);
        }
        return dp[{{ind,sum},count}] = ans;
    }
    int threeSumSmaller(vector<int> &nums, int target) {
        
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int count = 0;
        int ans = 0;

        int maxsum = 0;

        map<pair<pair<int,int>,int>,int> dp;

        return solve(0, 0, nums,target,count,dp);
    }
};
