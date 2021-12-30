class Solution {
public:
    int solve(int ind, int prev, string ring, string key, vector<vector<int>> &dp){
        
        if(ind == key.size()){
            return 0;
        }
        
        if(dp[ind][prev] != -1){
            return dp[ind][prev];
        }
        
        int minsteps = INT_MAX;
        
        for(int i = 0; i < ring.size(); i++){
            if(ring[i] == key[ind]){
                if(i >= prev){
                    int n = ring.size();
                    int temp = abs(i - prev - n);
                    minsteps = min(minsteps, solve(ind + 1, i, ring, key, dp) + i - prev + 1);
                    minsteps = min(minsteps, solve(ind + 1, i, ring, key, dp) + temp + 1);
                }
                else{
                    int n = ring.size();
                    int temp = abs(prev - i - n);
                    minsteps = min(minsteps, solve(ind + 1, i, ring, key, dp) + temp + 1);
                    minsteps = min(minsteps, solve(ind + 1, i, ring, key, dp) + abs(i - prev) + 1);
                }
            }
        }
        return dp[ind][prev] = minsteps;
    }
    int findRotateSteps(string ring, string key) {
        
        int len1 = ring.size(), len2 = key.size();
        
        int minsteps = INT_MAX, steps = 0;
        
        vector<vector<int>> dp(len2, vector<int>(len1,-1));
        
        return solve(0, 0, ring, key, dp);
    }
};
