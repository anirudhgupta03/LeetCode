//Similat to Painter's Problem
class Solution {
public:
    bool isPossible(int t, vector<int> &nums, int m){
        
        int count = 1;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            sum += nums[i];
            
            if(sum > t){
                count++;
                sum = nums[i];
            }
        }
        
        if(count > m){
            return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        
        int lo = INT_MIN, hi = 0;
        
        for(auto x: nums){
            lo = max(lo,x);
            hi += x;
        }
        
        int ans;
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(isPossible(mid,nums,m)){
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
