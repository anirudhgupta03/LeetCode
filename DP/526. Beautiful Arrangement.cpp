//Top-Down
//DP + Bitmasking
class Solution {
public:
    int solve(int ind, int n, int &mask, vector<vector<int>> &dp){
        
        if(mask == (1 << n) - 1){
            return 1;
        }
        
        if(dp[ind][mask] != -1){
            return dp[ind][mask];
        }
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) == 0){
                if(ind % (i + 1) == 0 || (i + 1) % ind == 0){
                    mask |= (1 << i);
                    count += solve(ind + 1, n, mask, dp);
                    mask &= (~(1 << i));
                }
            }
        }
        return dp[ind][mask] = count;
    }
    int countArrangement(int n) {
        
        int mask = 0;
        int temp = (1 << n);
        vector<vector<int>> dp(n + 1, vector<int>(temp, -1));
        return solve(1, n, mask, dp);
    }
};

//Ref: https://www.youtube.com/watch?v=xf8qAkqDr8Y
class Solution {
public:
    void dfs(vector<int> &vis, int ind, int &count, int n){
        
        if(ind > n){
            count++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && ((ind % (i + 1) == 0) || (i + 1) % ind == 0)){
                vis[i] = ind;
                dfs(vis, ind + 1, count, n);
                vis[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> vis(n,0);
        int count = 0;
        dfs(vis, 1, count, n);
        return count;
    }
};
