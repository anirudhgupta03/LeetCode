//Top-Down Approach
class Solution {
public:
    map<pair<int,int>,bool> dp;
    bool solve(int ind, int k, vector<int> &stones){
        
        if(ind == stones.size() - 1){
            return true;
        }
        if(dp.find({ind, k}) != dp.end()){
            return dp[{ind,k}];
        }
        for(int i = ind + 1; i < stones.size(); i++){
            
            int temp = stones[i] - stones[ind];
            if(temp == k || temp == k - 1 || temp == k + 1){
                bool flag = solve(i, temp, stones);
                if(flag) return dp[{ind,k}] = true;
            }
        }
        return dp[{ind,k}] = false;
    }
    bool canCross(vector<int>& stones) {
        
        if(stones[1] > 1){
            return false;
        }
        dp.clear();
        return solve(1, 1, stones);
    }
};
