//Method - 1
#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &cost)
{
	int n = cost.size();
    
    vector<vector<int>> dp(3, vector<int>(n));
    
    dp[0][0] = cost[0][0];
    dp[1][0] = cost[0][1];
    dp[2][0] = cost[0][2];
    
    for(int i = 1; i < n; i++){
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + cost[i][0];
        dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + cost[i][1];
        dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + cost[i][2];
    }
    return min({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
}

//Method - 2
#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &cost)
{
	int n = cost.size();
    
    int r,g,y;
    
    g = cost[0][0];
    r = cost[0][1];
    y = cost[0][2];
    
    for(int i = 1; i < n; i++){
        int tg = g, tr = r, ty = y;
        g = min(tr,ty) + cost[i][0];
        r = min(tg,ty) + cost[i][1];
        y = min(tg,tr) + cost[i][2];
    }
    return min({g,r,y});
}
