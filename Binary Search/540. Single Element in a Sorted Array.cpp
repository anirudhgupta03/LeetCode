//Ref: https://www.youtube.com/watch?v=AZOmHuHadxQ&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=8
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int preEle = (mid - 1 >= 0) ? nums[mid - 1] : -1;
            int nextEle = (mid + 1 < n) ? nums[mid + 1] : -1;
            if(nums[mid] != preEle && nums[mid] != nextEle){
                return nums[mid];
            }
            else{
                if(nums[mid] == preEle){
                    if(mid % 2 == 0) hi = mid - 1;
                    else lo = mid + 1;
                }
                else{
                    if(mid % 2 == 0) lo = mid + 1;
                    else hi = mid - 1;
                }
            } 
        }
        return -1;
    }
};
