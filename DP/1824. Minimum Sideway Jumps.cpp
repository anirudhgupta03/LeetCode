//Ref: https://leetcode.com/problems/minimum-sideway-jumps/discuss/1152537/C%2B%2B-Memoised-DP-solution
class Solution {
public:
    int solve(int lane, int point, vector<int> &obstacles, vector<vector<int>> &dp){
        
        if(point == obstacles.size() - 2){
            return dp[lane][point] = 0;
        }
        
        if(dp[lane][point] != -1){
            return dp[lane][point];
        }
        
        if(obstacles[point+1] != lane){
            return dp[lane][point] = solve(lane,point+1,obstacles,dp);
        }
        
        
        int l1 = 0, l2 = 0;
        
        if(lane == 1){
            l1 = 2;
            l2 =3;
        }
        else if(lane == 2){
            l1 = 1;
            l2 = 3;
        }
        else{
            l1 = 1;
            l2 = 2;
        }
        
        if(obstacles[point] == l1){
            return dp[lane][point] = 1 + solve(l2,point + 1,obstacles,dp);
        }
        else if(obstacles[point] == l2){
            return dp[lane][point] = 1 + solve(l1,point + 1,obstacles,dp);
        }
        else{
            return dp[lane][point] = 1 + min(solve(l1,point + 1,obstacles,dp),solve(l2,point + 1,obstacles,dp));
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        
        vector<vector<int>> dp(4,vector<int>(n,-1));
        
        return solve(2,0,obstacles,dp);
    }
};
