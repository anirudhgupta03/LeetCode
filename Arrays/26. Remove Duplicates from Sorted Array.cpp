class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            int ele = nums[j];
            while(j < nums.size() && ele == nums[j]){
                j++;
            }
            nums[i] = ele;
            i++;
        }
        return i;
    }
};
