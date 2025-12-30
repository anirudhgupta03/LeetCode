//Top-Down
//TC: O(N*N)
//SC: O(N*N) + Auxilliary Stack Space
class Solution {
public:
    int findLengthOfLIS(int ind, int preInd, vector<int>& nums, vector<vector<int>> &dp){
        if(ind == nums.size() + 1) return 0;
        if(dp[ind][preInd] != -1) return dp[ind][preInd];
        int take = 0;
        if(preInd == 0 || nums[ind - 1] > nums[preInd - 1]){
            take = findLengthOfLIS(ind + 1, ind, nums, dp) + 1;
        }
        int notTake = findLengthOfLIS(ind + 1, preInd, nums, dp);
        return dp[ind][preInd] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return findLengthOfLIS(1, 0, nums, dp);
    }
};

//Bottom-Up
//Tabulation
//TC: O(N*N)
//SC: O(N*N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for(int ind = n; ind >= 1; ind--){
            for(int preInd = ind - 1; preInd >= 0; preInd--){
                int take = 0;
                if(preInd == 0 || nums[ind - 1] > nums[preInd - 1]){
                    take = dp[ind + 1][ind] + 1;
                }
                int notTake = dp[ind + 1][preInd];
                dp[ind][preInd] = max(take, notTake);
            }
        }
        return dp[1][0];
    }
};

//Bottom-Up
//Tabulation + Space Optimization
//TC: O(N*N)
//SC: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevDP(n + 1, 0);
        for(int ind = n; ind >= 1; ind--){
            vector<int> currDP(n + 1, 0);
            for(int preInd = ind - 1; preInd >= 0; preInd--){
                int take = 0;
                if(preInd == 0 || nums[ind - 1] > nums[preInd - 1]){
                    take = prevDP[ind] + 1;
                }
                int notTake = prevDP[preInd];
                currDP[preInd] = max(take, notTake);
            }
            prevDP = currDP;
        }
        return prevDP[0];
    }
};

//TC: O(N*N)
//SC: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxLen = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            maxLen = max(maxLen,dp[i]);
        }
        return maxLen;
    }
};

//TC: O(NlogN)
//SC: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> v;
        
        v.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > v.back()){
                v.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[ind] = nums[i];
            }
        }
        return v.size();
    }
};
