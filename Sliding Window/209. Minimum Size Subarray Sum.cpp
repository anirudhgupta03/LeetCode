class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int lo = 0, hi = 0, sum = 0;
        
        int minlen = INT_MAX;
        
        while(hi < nums.size()){
            sum += nums[hi];
            while(lo <= hi && sum >= target){
                minlen = min(minlen, hi - lo + 1);
                sum -= nums[lo];
                lo++;
            }
            hi++;
        }
        if(minlen == INT_MAX){
            return 0;
        }
        return minlen;
    }
};
