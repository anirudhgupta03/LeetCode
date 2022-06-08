//Method - 1
//Gives TLE
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

//Method - 2
class Solution {
public:
    bool alreadyHappened(vector<int> &sides, int pos){
        for(int i = 0; i < pos; i++){
            if(sides[i] == sides[pos]){
                return true;
            }
        }
        return false;
    }
    bool solve(int ind, int sum, vector<int> &v, vector<int> &nums, int tsum){
        
        if(sum == 0 && ind == nums.size()){
            return true;
        }
        if(sum == 0 || ind == nums.size()){
            return false;
        }
        
        for(int i = 0; i < v.size(); i++){
            if(alreadyHappened(v, i)){
                continue;
            }
            if(v[i] + nums[ind] <= tsum){
                v[i] += nums[ind];
                bool flag = solve(ind + 1, sum - nums[ind], v, nums, tsum);
                if(flag) return true;
                v[i] -= nums[ind];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        if(sum % k != 0){
            return false;
        }
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        if(nums[0] > sum/k || nums.size() < k){
            return false;
        }
        
        vector<int> v(k, 0);
        
        return solve(0, sum, v, nums, sum/k);
    }
};
