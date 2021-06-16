//Time Complexity - O(2*logN)
//Space Complexity - O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lo = 0, hi = nums.size() - 1;
        
        int start = -1, end = -1;
        
        vector<int> res;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(nums[mid] == target){
                start = mid;
                hi = mid - 1;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        if(start == -1){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        lo = 0, hi = nums.size() - 1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(nums[mid] == target){
                end = mid;
                lo = mid + 1;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        res.push_back(start);
        res.push_back(end);
        return res;
    }
};
