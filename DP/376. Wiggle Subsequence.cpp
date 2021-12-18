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
