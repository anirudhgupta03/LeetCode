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

//Top-Down
//TC: O(3*n)
//SC: O(3*n) + Auxilliary Stack Space
class Solution {
public:
    int solve(int lane, int ind, vector<int> &obstacles, vector<vector<int>> &dp){
        
        if(ind == obstacles.size() - 1){
            return 0;
        }
        if(dp[lane][ind] != -1){
            return dp[lane][ind];
        }
        
        int minSteps = INT_MAX;
        if(obstacles[ind + 1] != lane){
            minSteps = min(minSteps, solve(lane, ind + 1, obstacles, dp));
        }
        
        int otherlane1, otherlane2;
        
        if(lane == 1){
            otherlane1 = 2;
            otherlane2 = 3;
        }
        if(lane == 2){
            otherlane1 = 1;
            otherlane2 = 3;
        }
        if(lane == 3){
            otherlane1 = 1;
            otherlane2 = 2;
        }
        
        if(obstacles[ind] != otherlane1 && obstacles[ind + 1] != otherlane1){
            int temp = solve(otherlane1, ind + 1, obstacles, dp);
            if(temp != INT_MAX){
                minSteps = min(minSteps, temp + 1);
            }
        }
        
        if(obstacles[ind] != otherlane2 && obstacles[ind + 1] != otherlane2){
            int temp = solve(otherlane2, ind + 1, obstacles, dp);
            if(temp != INT_MAX){
                minSteps = min(minSteps, temp + 1);
            }
        }
        return dp[lane][ind] = minSteps;
    }
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solve(2, 0, obstacles, dp);
    }
};

//Bottom-Up
//TC: O(3*n)
//SC: O(3*n)
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n));
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int lane = 1; lane <= 3; lane++){
                if(ind == n - 1){
                    dp[lane][ind] = 0;
                }
                else{
                    int minSteps = INT_MAX;

                    if(obstacles[ind + 1] != lane){
                        minSteps = min(minSteps, dp[lane][ind + 1]);
                    }

                    int otherlane1, otherlane2;

                    if(lane == 1){
                        otherlane1 = 2;
                        otherlane2 = 3;
                    }
                    if(lane == 2){
                        otherlane1 = 1;
                        otherlane2 = 3;
                    }
                    if(lane == 3){
                        otherlane1 = 1;
                        otherlane2 = 2;
                    }

                    if(obstacles[ind] != otherlane1 && obstacles[ind + 1] != otherlane1){
                        int temp = dp[otherlane1][ind + 1];
                        if(temp != INT_MAX){
                            minSteps = min(minSteps, temp + 1);
                        }
                    }

                    if(obstacles[ind] != otherlane2 && obstacles[ind + 1] != otherlane2){
                        int temp = dp[otherlane2][ind + 1];
                        if(temp != INT_MAX){
                            minSteps = min(minSteps, temp + 1);
                        }
                    }
                    dp[lane][ind] = minSteps;
                }
            }
        }
        return dp[2][0];
    }
};
