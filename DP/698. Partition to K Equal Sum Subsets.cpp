class Solution {
public:
    #define ppiivi pair<pair<int,int>,vector<int>>
    int solve(int sum, int reqsum, int count, int k, vector<int> &nums, map<ppiivi,int> &dp, vector<int> &vis){
        
        if(count == k){
            return 1;
        }
        
        if(dp.find({{sum, count},vis}) != dp.end()){
            return dp[{{sum,count},vis}];
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] < reqsum && vis[i] == 0){
                vis[i] = 1;
                bool flag = solve(sum + nums[i], reqsum, count, k, nums, dp, vis);
                vis[i] = 0;
                if(flag) return dp[{{sum,count},vis}] =  1;
            }
            else if(sum + nums[i] == reqsum && vis[i] == 0){
                vis[i] = 1;
                bool flag = solve(0, reqsum, count + 1, k, nums, dp, vis);
                vis[i] = 0;
                if(flag) return dp[{{sum,count},vis}] = 1;
            }
        }
        return dp[{{sum,count},vis}] = 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        
        sort(nums.begin(),nums.end());
        
        for(auto x: nums){
            sum += x;
        }
        
        if(sum % k != 0){
            return false;
        }
        
        vector<int> vis(nums.size(),0);
        
        map<ppiivi,int> dp;
        
        vector<int> temp;
        
        return solve(0,sum/k,0,k,nums, dp, vis); 
    }
};
