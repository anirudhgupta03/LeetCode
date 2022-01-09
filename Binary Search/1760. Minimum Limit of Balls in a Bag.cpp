class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int penalty){
        
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % penalty == 0){
                count += (nums[i]/penalty) - 1;
            }
            else{
                count += (nums[i]/penalty);
            }
        }
        if(count <= maxOperations){
            return true;
        }
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int lo = 1, hi = 1e9;
        int ans;
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(isPossible(nums, maxOperations, mid)){
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
