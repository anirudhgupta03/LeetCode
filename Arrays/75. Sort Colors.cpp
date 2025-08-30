//Ref: https://www.youtube.com/watch?v=tp8JIuCXBaU&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB
//Optimal Solution
//Dutch National Flag Algorithm
//00000...
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0, j = n - 1, k = 0;
        while(k <= j){
            if(nums[k] == 0){
                swap(nums[i], nums[k]);
                i++;
                k++;
            }
            else if(nums[k] == 2){
                swap(nums[j], nums[k]);
                j--;
            }
            else{
                k++;
            }
        }
    }
};
