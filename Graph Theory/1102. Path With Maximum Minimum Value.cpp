//https://www.codingninjas.com/codestudio/problems/path-with-maximum-and-minimum-value_1281861?leftPanelTab=0
//Ref: https://wentao-shao.gitbook.io/leetcode/graph-search/1102.path-with-maximum-minimum-value

#include<bits/stdc++.h>
using namespace std;
#define pipii pair<int,pair<int,int>>
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

struct cmp{
    bool operator()(pipii p1, pipii p2){
        return p1.first < p2.first;
    }
};
int pathWithMaxMinValue(vector<vector<int>> &arr)
{
	int m = arr.size(), n = arr[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    
    priority_queue<pipii, vector<pipii>, cmp> pq;
    pq.push({arr[0][0],{0,0}});
    
    int ans = INT_MAX;
    while(!pq.empty()){
        
        int currval = pq.top().first, currx = pq.top().second.first, curry = pq.top().second.second;
        pq.pop();
        
        ans = min(ans, currval);
        if(currx == m - 1 && curry == n - 1){
            return ans;
        }
        
        for(int i = 0; i < 4; i++){
            int xo = currx + dx[i], yo = curry + dy[i];
            if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                if(vis[xo][yo] == 0){
                    vis[xo][yo] = 1;
                    pq.push({arr[xo][yo],{xo,yo}});
                }
            }
        }
    }
    return -1;
}
