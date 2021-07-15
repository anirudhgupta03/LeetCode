class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        reverse(nums.begin(),nums.begin() + n - k % n);
        
        reverse(nums.begin() + n - k % n, nums.end());
        
        reverse(nums.begin(),nums.end());
    }
};
