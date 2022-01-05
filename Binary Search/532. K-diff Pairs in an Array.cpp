class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            int temp = nums[i] + k;
            
            int lo = i + 1, hi = nums.size() - 1;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                
                if(nums[mid] > temp){
                    hi = mid - 1;
                }
                else if(nums[mid] == temp){
                    count++;
                    break;
                }
                else{
                    lo = mid + 1;
                }
            }
        }
        return count;
    }
};
