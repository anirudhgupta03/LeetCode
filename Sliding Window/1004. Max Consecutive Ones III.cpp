//Ref: https://www.youtube.com/watch?v=pwaVTOazeb4
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int lo = 0, hi = 0;
        
        int fc = 0, maxlen = 0;
        
        while(hi < nums.size()){
            
            if(nums[hi] == 1) hi++;
            
            else if(nums[hi] == 0 && fc < k){
                hi++;
                fc++;
            }
            else if(nums[hi] == 0 && fc == k){
                
                while(lo <= hi){
                    maxlen = max(maxlen, hi - lo);
                    if(nums[lo] == 1) lo++;
                    else if(nums[lo] == 0){
                        maxlen = max(maxlen, hi - lo);
                        lo++;
                        break;
                    }
                }
                hi++;
            }
        }
        maxlen = max(maxlen, hi - lo);
        return maxlen;
    }
};

//Method - 2
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int maxLen = 0;
        
        int lo = 0, hi = 0;
        
        while(hi < nums.size()){
            
            if(nums[hi] == 0){
                k--;
                if(k < 0){
                    while(lo < hi && nums[lo] == 1){
                        lo++;
                    }
                    lo++;
                    k++;
                }
            }
            hi++;
            maxLen = max(maxLen, hi - lo);
        }
        return maxLen;
    }
};
