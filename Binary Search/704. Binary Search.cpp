//Ref: https://www.youtube.com/watch?v=MHf6awe89xw&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};
