//Method - 1
//Ref: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/5149850/fastest-100-easiest-shortest-binary-search-multiple-langs
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0], nums[1]);
        
        int lo = 0, hi = n - 1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            int prevele = mid == 0 ? nums[n - 1] : nums[mid - 1];
            int nextele = mid == n - 1 ? nums[0] : nums[mid + 1];
            
            if(nums[mid] < prevele && nums[mid] < nextele){
                return nums[mid];
            }
            else if(nums[mid] <= nums[hi]){            
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return 0;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=nhEMDKMB44g&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=6
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        
        int lo = 0, hi = n - 1, ans = INT_MAX;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if(nums[lo] <= nums[hi]){        //If the entire search space is sorted
                ans = min(ans, nums[lo]);
                return ans;
            }
            
            if(nums[mid] >= nums[lo]){       
                ans = min(ans, nums[lo]);
                lo = mid + 1;                //Eliminating the left sorted half
            }
            else{
                ans = min(ans, nums[mid]);
                hi = mid - 1;                //Eliminating the right sorted half
            }
        }
        return -1;
    }
};
