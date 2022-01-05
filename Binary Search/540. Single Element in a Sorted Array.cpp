class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1){
            return nums[0];
        }
        
        int lo = 0, hi = n - 1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(mid % 2 == 0){
                if(mid == 0){
                    if(nums[mid] != nums[mid+1]){
                        return nums[mid];
                    }
                }
                else if(mid == n - 1){
                    if(nums[mid] != nums[mid-1]){
                        return nums[mid];
                    }
                }
                else if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid + 1]){
                    return nums[mid];
                }
                else if(nums[mid] == nums[mid-1]){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            else{
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid + 1]){
                    return nums[mid];
                }
                else if(nums[mid] == nums[mid - 1]){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
        return 0;
    }
};
