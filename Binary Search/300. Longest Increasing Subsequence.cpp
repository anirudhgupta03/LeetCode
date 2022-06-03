class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> lis;
        
        lis.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > lis.back()){
                lis.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[ind] = nums[i];
            }
        }
        return lis.size();
    }
};
