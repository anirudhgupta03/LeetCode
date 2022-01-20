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
