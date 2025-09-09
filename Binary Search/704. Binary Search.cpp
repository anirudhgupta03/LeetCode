//Ref: https://www.youtube.com/watch?v=MHf6awe89xw&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh
//Iterative
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

//Recursive
class Solution {
public:
    int binarySearch(int lo, int hi,vector<int> &nums, int target){
        if(lo > hi) return -1;
        int mid = lo + (hi - lo)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return binarySearch(lo, mid - 1, nums, target);
        return binarySearch(mid + 1, hi, nums, target);
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size() - 1, nums, target);
    }
};
