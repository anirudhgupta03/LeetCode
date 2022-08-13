//Top-Down
//TC: O(n*d)
//SC: O(n*d) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, vector<int> &jobDifficulty, int d, vector<vector<int>> &dp){
        
        if(ind == jobDifficulty.size() && d == 0){
            return 0;
        }
        if(ind == jobDifficulty.size() || d == 0){
            return INT_MAX;
        }
        
        if(dp[ind][d] != -1){
            return dp[ind][d];
        }
        int minDiff = INT_MAX, maxVal = INT_MIN;
        
        for(int i = ind; i < jobDifficulty.size(); i++){
            maxVal = max(maxVal, jobDifficulty[i]);
            int temp = solve(i + 1, jobDifficulty, d - 1, dp);
            if(temp != INT_MAX){
                minDiff = min(minDiff, temp + maxVal);
            }
        }
        return dp[ind][d] = minDiff;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        
        if(n < d){
            return -1;
        }
      
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        return solve(0, jobDifficulty, d, dp);
    }
};

//Bottom-Up
//TC: O(n*d)
//SC: O(n*d)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int td) {
        
        int n = jobDifficulty.size();
        
        if(n < td){
            return -1;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(td + 1));
        
        for(int ind = n; ind >= 0; ind--){
            for(int d = 0; d <= td; d++){
                if(ind == n && d == 0){
                    dp[ind][d] = 0;
                }
                else if(ind == n || d == 0){
                    dp[ind][d] = INT_MAX;
                }
                else{
                    int minDiff = INT_MAX, maxVal = INT_MIN;
                    for(int i = ind; i < n; i++){
                        maxVal = max(maxVal, jobDifficulty[i]);
                        int temp = dp[i + 1][d - 1];
                        if(temp != INT_MAX){
                            minDiff = min(minDiff, temp + maxVal);
                        }
                    }
                    dp[ind][d] = minDiff;
                }
            }
        }
        return dp[0][td];
    }
};
