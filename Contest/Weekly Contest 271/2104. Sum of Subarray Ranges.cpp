class Solution {
public:
    #define ll long long
    long long subArrayRanges(vector<int>& nums) {
        
        ll sum = 0;
        
        int n = nums.size();
        int large = INT_MIN, small = INT_MAX;
        
        for(int i = 0; i < n; i++){
            large = INT_MIN, small = INT_MAX;
            for(int j = i; j < n; j++){
                if(nums[j] > large) large = nums[j];
                if(nums[j] < small) small = nums[j];
                sum += large - small;
            }
        }
        
        return sum;
    }
};
