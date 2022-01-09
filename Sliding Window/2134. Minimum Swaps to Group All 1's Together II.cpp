//Ref: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/discuss/1676865/Python3-Java-C%2B%2B-Easy-Sliding-Window-O(n)
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        int ones = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) ones++;
        }
        
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        
        int count = 0, maxcount = 0;
        
        for(int i = 0; i < ones; i++){
            if(nums[i] == 1){
                count++;
            }    
        }
        
        int lo = 0, hi = ones;
        
        while(hi < 2*n){
            
            maxcount = max(maxcount, count);
            
            if(nums[lo] == 1){
                count--;
            }
            
            if(nums[hi] == 1){
                count++;
            }
            
            lo++;
            hi++;
        }
        return ones - maxcount;
    }
};
