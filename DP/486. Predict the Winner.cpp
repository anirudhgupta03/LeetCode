//Ref: https://www.youtube.com/watch?v=ww4V7vRIzSk
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
