class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        for(int i = 0; i < nums.size() - 2; i++){
            int lo = n - 2, hi = n - 1;
            
            while(lo > i){
                if(lo == hi){
                    lo--;
                }
                else if(nums[i] + nums[lo] > nums[hi]){
                    count += hi - lo;
                    lo--;
                }
                else{
                    hi--;
                }
            }
        }
        return count;
    }
};
