//Ref: https://www.youtube.com/watch?v=JDOXKqF60RQ&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=11
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1){
            return;
        }
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        
        if(i>=0){
            int j=nums.size()-1;
            while(nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        
        int j=nums.size()-1;
        i++;
        while(i<j){
            swap(nums[i],nums[j]);
                i++;
                j--;
        }
    }
};
