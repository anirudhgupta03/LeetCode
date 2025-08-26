//Method - 1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        bool flag = false;

        for(int i = 0; i < n; i++){
            if(abs(nums[i]) != n){
                nums[abs(nums[i])] = -1*(abs(nums[abs(nums[i])]));
            }
            else{
                flag = true;
            }
        }
        int ans = n;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i;
            }
            else if(nums[i] == 0){
                ans = i;
            }
        }
        return (flag == false) ? n : ans;
    }
};

//Method - 2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        
        for(auto x: nums){
            sum += x;
        }
        
        return n*(n+1)/2 - sum;
    }
};
