//Top-Down Approach
class Solution {
public:
    bool solve(int ind, int k, vector<int> &stones, map<pair<int,int>,int> &dp){
        
        if(ind == stones.size() - 1){
            return true;
        }
        
        if(dp.find({ind,k}) != dp.end()){
            return dp[{ind,k}];
        }
        for(int i = ind + 1; i < stones.size(); i++){
            if(stones[i] - stones[ind] == k - 1){
                bool flag = solve(i, k - 1, stones, dp);
                if(flag) return dp[{ind,k}] = true;
            }
            else if(stones[i] - stones[ind] == k){
                bool flag = solve(i, k, stones, dp);
                if(flag) return dp[{ind,k}] = true;
            }
            else if(stones[i] - stones[ind] == k + 1){
                bool flag = solve(i, k + 1, stones, dp);
                if(flag) return dp[{ind,k}] = true;
            }
        }
        return dp[{ind,k}] = false;
    }
    bool canCross(vector<int>& stones) {
        
        if(stones[1] > 1){
            return false;
        }
        map<pair<int,int>,int> dp;
        return solve(1, 1, stones, dp);
    }
};
