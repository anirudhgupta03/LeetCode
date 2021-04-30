//Kadane's Algorithm Implementation
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int curr_sum = nums[0], max_sum = INT_MIN;
        
        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i] > nums[i-1]){
                curr_sum += nums[i];
            }
            
            else{
                max_sum = max(max_sum,curr_sum);
                curr_sum = nums[i];
            }
        }
        max_sum = max(max_sum,curr_sum);
        return max_sum;
    }
};
