class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        vector<int> temp(nums.size());
        
        sort(nums.begin(),nums.end());
        
        int ind = nums.size() - 1;
        
        for(int i = 1; i < temp.size(); i += 2){
            temp[i] = nums[ind];
            ind--;
        }
        
        for(int i = 0; i < temp.size(); i += 2){
            temp[i] = nums[ind];
            ind--;
        }
        
        nums = temp;
    }
};
