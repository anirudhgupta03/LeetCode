class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int lo = 0, hi = nums.size() - 1;
        
        while(lo <= hi){
             // to avoid duplicates
            while (lo < hi && nums[lo] == nums[lo + 1])
              ++lo;
            while (lo < hi && nums[hi] == nums[hi - 1])
              --hi;
            int mid = (lo + hi)/2;
            
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] <= nums[hi]){
                
                if(target >= nums[mid] && target <= nums[hi]){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            else{
                
                if(target >= nums[lo] && target <= nums[mid]){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
        }
        return false;
    }
};
