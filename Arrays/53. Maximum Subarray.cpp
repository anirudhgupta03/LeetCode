//Ref: https://www.youtube.com/watch?v=AHZpyENo7k4&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=8
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
