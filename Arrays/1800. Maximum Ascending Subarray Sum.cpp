class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int currSum = nums[0], maxSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i] <= nums[i-1]){
                maxSum = max(maxSum,currSum);
                currSum = nums[i];
            }
            else{
                currSum += nums[i];
            }
        }
        maxSum = max(maxSum,currSum);
        return maxSum;
    }
};
