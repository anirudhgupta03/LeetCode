//Ref: https://www.youtube.com/watch?v=qkUZ87NCYSw
//3D DP
class Solution {
public:
    #define ppiivi pair<pair<int,int>,vector<int>>
    int solve(int ind, int zeros, int ones, int m, int n, int len, vector<pair<int,int>> &binary, vector<vector<vector<int>>> &dp){
        if(ind == len || zeros == m && ones == n){
            return 0;
        }
        if(dp[zeros][ones][ind] != -1){
            return dp[zeros][ones][ind];
        }
        
        int count1 = 0;
        if(zeros + binary[ind].first <= m && ones + binary[ind].second <= n)
            count1 = solve(ind + 1, zeros + binary[ind].first, ones + binary[ind].second, m, n, len, binary, dp) + 1;
        
        int count2 = solve(ind + 1, zeros, ones, m, n, len, binary, dp);
        
        return dp[zeros][ones][ind] = max(count1, count2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int len = strs.size();
        
        vector<pair<int,int>> binary(len);
        
        for(int i = 0; i < strs.size(); i++){
            int zeros = 0, ones = 0;
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] == '1') ones++;
                else                  zeros++;
            }
            binary[i] = {zeros,ones};
        }
        
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(len + 1, -1)));
        
        return solve(0,0,0,m, n, len, binary, dp);
    }
};
