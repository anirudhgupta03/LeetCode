//Method - 1
//TLE
//Time Complexity - O(N*N)
//Space Complexity - O(N)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n,1);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            if(dp[i] >= 3){
                return true;
            }
        }
        
        return false;
    }
};

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(N)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int leftmin[n], rightmax[n];
        
        leftmin[0] = nums[0];
        rightmax[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++){
            leftmin[i] = min(leftmin[i-1],nums[i]);
        }
        
        for(int i = n - 2; i >= 0; i--){
            rightmax[i] = max(rightmax[i+1],nums[i]);
        }
        
        for(int i = 1; i <= n - 2; i++){
            if(nums[i] > leftmin[i-1] && nums[i] < rightmax[i+1]){
                return true;
            }
        }
        
        return false;
    }
};

//Method - 3
//Time Complexity - O(N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=xZ5FBqk-cFw
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int f = INT_MAX, s = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] <= f){
                f = nums[i];
            }
            else if(nums[i] <= s){
                s = nums[i];
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};
