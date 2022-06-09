//Method - 1
//TC - O(N)
//SC - O(N)
//Ref: https://www.youtube.com/watch?v=SuM12LERW_M
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int maxNum = INT_MIN;
        
        for(auto &x: nums){
            maxNum = max(maxNum, x);
        }
        
        vector<int> v(maxNum + 1, 0);
        
        for(auto &x: nums){
            v[x] += x;
        }
        
        if(maxNum == 1){
            return v[1];
        }
        vector<int> dp(maxNum + 1, 0);
        dp[1] = v[1];
        dp[2] = max(v[1], v[2]);
        
        for(int i = 3; i <= maxNum; i++){
            dp[i] = max(dp[i-1], v[i] + dp[i-2]);
        }
        return dp[maxNum];
    }
};

//Method - 2
//TC - O(N)
//SC - O(1)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        int maxVal = *max_element(nums.begin(), nums.end());
        
        vector<int> v(maxVal + 1, 0);
        
        for(int i = 0; i < nums.size(); i++){
            v[nums[i]]++;
        }
        
        int val1 = v[1];
        int val2 = max(v[1], 2*v[2]);
        
        for(int i = 3; i <= maxVal; i++){
            int val3 = max(val1 + i*v[i], val2);
            val1 = val2;
            val2 = val3;
        }
        return val2;
    }
};
