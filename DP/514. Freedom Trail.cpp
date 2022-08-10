class Solution {
public:
    int solve(int ind1, int ind2, int len1, int len2, string &ring, string &key, vector<vector<int>> &dp){
        
        if(ind2 == len2){
            return 0;
        }
        
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        int minSteps =  INT_MAX;
        
        for(int i = 0; i < len1; i++){
            if(ring[i] == key[ind2]){
                if(i > ind1){
                    minSteps = min(minSteps, solve(i, ind2 + 1, len1, len2, ring, key, dp) + min(i - ind1, ind1 + len1 - i) + 1);   
                }
                else{
                    minSteps = min(minSteps, solve(i, ind2 + 1, len1, len2, ring, key, dp) + min(ind1 - i, i + len1 - ind1) + 1);   
                }
            }
        }
        return dp[ind1][ind2] = minSteps;
    }
    int findRotateSteps(string ring, string key) {
        
        int len1 = ring.size(), len2 = key.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        return solve(0, 0, len1, len2, ring, key, dp);
    }
};
