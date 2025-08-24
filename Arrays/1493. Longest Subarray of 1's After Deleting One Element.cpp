class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int count = 0, preCount = 0, currCount = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count = max(count, preCount + currCount);
                preCount = currCount;
                currCount = 0;
            }
            else{
                currCount++;
            }
        }
        count = max(count, preCount + currCount);
        if(count == n){
            return count - 1;
        }
        return count;
    }
};
