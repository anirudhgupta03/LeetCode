class Solution {
public:
    int findMin(vector<int>& A) {
        
        int n = A.size();
    
        if(n == 1){
            return A[0];
        }
        int lo = 0, hi = n - 1;

        while(lo <= hi){

            int mid = (lo + hi)/2;
            int prev = (mid+n-1)%n;
            int next = (mid + 1)%n;

            if(A[mid] < A[prev] && A[mid] < A[next]){
                return A[mid];
            }
            else if(A[mid] < A[n-1]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return 0;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1){
            return nums[0];
        }
        int lo = 0, hi = nums.size() - 1;
        
        while(lo <= hi){
            
            int mid = (lo+hi)/2;
            
            int next = (mid+1)%n;
            int prev = (mid + n - 1)%n;
            
            if(nums[lo] < nums[hi]){
                return nums[lo];
            }
            if(nums[mid] < nums[next] && nums[mid] < nums[prev]){
                return nums[mid];
            }
            else if(nums[mid] >= nums[lo]){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return 0;
    }
};
