class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;

        for(int ele: nums){
            sum += ele;
            maxSum = max(maxSum, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};
