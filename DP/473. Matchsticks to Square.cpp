class Solution {
public:
    #define ppiivi pair<pair<int,int>,vector<int>>
    bool solve(int cursum, int reqsum, int count, vector<int> &vis, vector<int>& matchsticks, map<ppiivi,int> &dp){
        
        if(count == 4){
            return true;
        }
        
        if(dp.find({{cursum, count},vis}) != dp.end()){
            return dp[{{cursum,count},vis}];
        }
        for(int i = 0; i < matchsticks.size(); i++){
            if(vis[i] == 0 && cursum + matchsticks[i] < reqsum){
                vis[i] = 1;
                bool flag = solve(cursum + matchsticks[i], reqsum, count, vis, matchsticks, dp);
                vis[i] = 0;
                if(flag) return dp[{{cursum,count},vis}] = true;
            }
            else if(vis[i] == 0 && cursum + matchsticks[i] == reqsum){
                vis[i] = 1;
                bool flag = solve(0, reqsum, count + 1, vis, matchsticks, dp);
                vis[i] = 0;
                if(flag) return dp[{{cursum,count},vis}] = true;
            }
        }
        return dp[{{cursum,count},vis}] = false;
    }
    bool makesquare(vector<int>& matchsticks) {
        
        int n = matchsticks.size();
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += matchsticks[i];
        }
        
        if(sum % 4 != 0){
            return false;
        }
        
        vector<int> vis(n,0);
        int count = 0;
        
        map<ppiivi,int> dp;
        
        return solve(0, sum/4, count, vis, matchsticks, dp);
    }
};
