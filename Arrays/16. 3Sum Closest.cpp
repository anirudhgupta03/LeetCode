//Time Complexity - O(N^2)
//Space Complexity - O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int closeSum = INT_MAX;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i <= nums.size() - 3; i++){
            
            int l = i + 1, r = nums.size() - 1;
            
            while(l < r){
                
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum < target){
                    if(closeSum == INT_MAX){
                        closeSum = sum;
                    }
                    else if(abs(sum-target) < abs(closeSum-target)){
                        closeSum = sum;
                    }
                    l++;
                }
                else if(sum > target){
                    if(closeSum == INT_MAX){
                        closeSum = sum;
                    }
                    else if(abs(sum-target) < abs(closeSum-target)){
                        closeSum = sum;
                    }
                    r--;
                }
                else{
                    return target;
                }
            }
        }
        return closeSum;
    }
};
