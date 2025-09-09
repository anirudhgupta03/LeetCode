//Ref: https://www.youtube.com/watch?v=6zhGS79oQ4k&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=2
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int lo = 0, hi = nums.size() - 1;
        
        int ans = nums.size();
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(nums[mid] >= target){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
