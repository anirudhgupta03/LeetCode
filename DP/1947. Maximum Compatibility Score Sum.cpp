//Top-Down
class Solution {
public:
    int solve(int ind, int &mask, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<vector<int>> &dp){
        
        if(ind == students.size()){
            return 0;
        }
        
        if(dp[ind][mask] != -1){
            return dp[ind][mask];
        }
        
        int ans = 0;
        for(int i = 0; i < mentors.size(); i++){
            if((mask & (1 << i)) == 0){
                int count = 0;
                for(int j = 0; j < mentors[i].size(); j++){
                    if(mentors[i][j] == students[ind][j]){
                        count++;
                    }
                }
                mask |= (1 << i);
                ans = max(ans, solve(ind+1, mask, students, mentors, dp) + count);
                mask &= (~(1 << i));
            }
        }
        return dp[ind][mask] = ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int m = mentors.size(), t = (1 << m);
        int mask = 0;
        
        vector<vector<int>> dp(m, vector<int>(t, -1));
        return solve(0, mask, students, mentors, dp);
    }
};
