class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<unordered_map<int,int>> dp(n);
        
        int ans = 2;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int x = nums[i] - nums[j];
                dp[i][x] = dp[j].count(x)?dp[j][x]+1:2;  
                ans=max(dp[i][x],ans);
            }
        }
        return ans;
    }
};
