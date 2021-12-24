class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int no = nums.size();
        
        for(int i = 0; i < no; i++){
            nums.push_back(nums[i]);
        }
        
        int n = nums.size();
        
        vector<int> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        int sum = 0;
        
        for(int i = 0; i < no; i++) sum += i*nums[i];
        
        int maxsum = sum;
        
        for(int i = 1; i < no; i++){
            sum += (no - 1)*nums[i-1];
            sum -= prefix[i + (no - 1)] - prefix[i];
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};
