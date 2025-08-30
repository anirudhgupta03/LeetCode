//Ref: //https://youtu.be/tp8JIuCXBaU?list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&t=451
//Optimal Solution
//Dutch National Flag Algorithm
//                                             Unsorted
//0......0             1.........1          ...............          2..........2
//0      lo-1          lo        mid - 1    mid(0/1/2)    hi         hi + 1     n - 1
//TC: O(N)
//SC: O(1)
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
