class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int end = -1;
        int maxVal = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            if(maxVal > nums[i]){
                end = i;
            }
            else{
                maxVal = nums[i];
            }
        }
        int st = 0;
        int minVal = nums[nums.size() - 1];
        
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] > minVal){
                st = i;
            }
            else{
                minVal = nums[i];
            }
        }
        return end - st + 1;
    }
};
