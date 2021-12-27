//Ref: https://www.youtube.com/watch?v=bZQI58quN6E
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k == 0){
            return 0;
        }
        
        int lo = 0, hi = 0, count = 0, prod = 1;
        
        while(hi < nums.size()){
            
            prod *= nums[hi];
            
            while(lo <= hi && prod >= k){
                prod /= nums[lo];
                lo++;
            }
            count += 1 + (hi - lo);
            hi++;
        }
        return count;
    }
};
