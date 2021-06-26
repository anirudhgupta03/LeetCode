class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int curr_max_prod = nums[0], curr_min_prod = nums[0];
        int prev_max_prod = nums[0], prev_min_prod = nums[0];
        
        int ans = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            
            curr_max_prod = max({prev_max_prod*nums[i], prev_min_prod*nums[i], nums[i]});
            curr_min_prod = min({prev_max_prod*nums[i], prev_min_prod*nums[i], nums[i]});
            
            ans = max(ans,curr_max_prod);
            
            prev_max_prod = curr_max_prod;
            prev_min_prod = curr_min_prod;
        }
        
        return ans;
    }
};
