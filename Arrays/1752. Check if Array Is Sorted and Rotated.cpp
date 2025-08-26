//Ref: https://www.youtube.com/watch?v=37E9ckMDdTk
class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        bool flag = false;
        
        int i = 1;
        while(i < nums.size()){
            if(nums[i] < nums[i - 1]){
                break;
            }
            i++;
        }
        if(i == nums.size()){
            return true;
        }
        i++;
        while(i < nums.size()){
            if(nums[i] < nums[i - 1]){
                return false;
            }
            i++;
        }

        if(nums[i - 1] <= nums[0]){
            return true;
        }
        return false;

    }
};
