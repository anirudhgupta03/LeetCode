class Solution {
public:
    #define ll long long
    int minPatches(vector<int>& nums, int n) {
        
        ll maxSum = 1;
        
        ll count = 0;
        
        ll i = 0;
        
        while(i < nums.size() && maxSum <= n){
            
            if(nums[i] <= maxSum){
                maxSum += nums[i];
                i++;
            }
            else{
                count++;
                maxSum += maxSum;
            }
        }
        
        while(maxSum < n){
            count++;
            maxSum = 2*maxSum;
        }
        
        return count;
    }
};
