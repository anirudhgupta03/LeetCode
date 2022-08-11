//Top-Down
//TC: O(n)
//SC: O(n) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind, vector<int> &cost, vector<int> &dp){
        
        if(ind >= cost.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        return dp[ind] = min(solve(ind + 1, cost, dp) + cost[ind], solve(ind + 2, cost, dp) + cost[ind]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};

//Bottom-Up
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n + 2, 0);
        
        for(int ind = n - 1; ind >= 0; ind--){
            dp[ind] = min(dp[ind + 1] + cost[ind], dp[ind + 2] + cost[ind]);
        }
        return min(dp[0], dp[1]);
    }
};

//Iterative
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        int val1 = 0, val2 = 0;
        
        for(int i = 2; i <= n; i++){
            int val3 = min(val2 + cost[i - 1], val1 + cost[i - 2]);
            val1 = val2;
            val2 = val3;
        }
        return val2;
    }
};
