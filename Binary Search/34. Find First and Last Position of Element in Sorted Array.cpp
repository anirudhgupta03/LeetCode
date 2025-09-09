//Ref: https://www.youtube.com/watch?v=hjR1IYVx9lY&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=3
//Method - 1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int lo = 0, hi = n - 1;

        int firstPos = -1, lastPos = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                firstPos = mid;
                hi = mid - 1;
            }
            else if(nums[mid] > target){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        lo = 0;
        hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                lastPos = mid;
                lo = mid + 1;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return {firstPos, lastPos};
    }
};

//Method - 2
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lb == n || nums[lb] != target){
            return {-1, -1};
        }
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {lb, ub - 1};
    }
};
