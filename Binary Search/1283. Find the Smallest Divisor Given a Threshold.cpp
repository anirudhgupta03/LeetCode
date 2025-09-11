//Ref: https://www.youtube.com/watch?v=UvBKTVaG6U8&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=14
class Solution {
public:
    int result(int div, vector<int> &nums){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += ceil((double)nums[i]/div);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        int ans;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(result(mid,nums) <= threshold){
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
