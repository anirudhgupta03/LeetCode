class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n <= 2){
            return n;
        }
        
        int count = 1, ele = nums[0], l = 0;
         
        for(int i = 1; i < n; i++){
            
            if(nums[i] != ele){
                nums[l] = ele;
                l++;
                if(count >= 2){
                    nums[l] = ele;
                    l++;
                }
                ele = nums[i];
                count = 1;
            }
            else{
                count++;
            }
        }
        nums[l] = ele;
        l++;
        if(count >= 2){
            nums[l] = ele;
            l++;
        }
        return l;
    }
};
