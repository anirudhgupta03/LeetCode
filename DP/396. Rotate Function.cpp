//Method - 1
//TC - O(N)
//SC - O(N)
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

//Method - 2
//TC - O(N)
//SC - O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum1 = 0, sum2 = 0;
        
        for(int i = 1; i < n; i++){
            sum1 += nums[i];
            sum2 += i*nums[i];
        }
        
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        
        int ans = sum2;
        
        for(int i = n; i < 2*n - 1; i++){
            sum2 -= sum1;
            sum2 += (n - 1)*nums[i];
            sum1 = sum1 - nums[i - n + 1] + nums[i];
            ans = max(ans, sum2);
        }
        return ans;
    }
};
