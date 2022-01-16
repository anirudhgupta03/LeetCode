//https://www.codingninjas.com/codestudio/problems/connecting-cities-with-minimum-cost_1386586?leftPanelTab=1
//Minimum Spanning Tree
//Method - 1
//Kruskal's Algorithm
#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[2] < v2[2];
}
int findp(int node, vector<int> &par){
    if(par[node] == node){
        return node;
    }
    return par[node] = findp(par[node], par);
}
void unionp(int node1, int node2, vector<int> &par){
    par[node2] = node1;
}
int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
	sort(connections.begin(), connections.end(), cmp);
    
    vector<int> par(n + 1);
    
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
    
    int cost = 0, count = 0;
    for(int i = 0; i < m; i++){      
        int paru = findp(connections[i][0], par);
        int parv = findp(connections[i][1], par);
        
        if(paru != parv){
            count++;
            cost += connections[i][2];
            unionp(paru, parv, par);
        }
    }
    if(count != n - 1){
        return -1;
    }
    return cost;
}

//Method - 2
//Prim's Algorithm
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
struct cmp{
  bool operator()(pii p1, pii p2){
      return p1.second > p2.second;
  }  
};
int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
	vector<pii> al[n + 1];
    
    for(int i = 0; i < m; i++){
        int u = connections[i][0], v = connections[i][1], w = connections[i][2];
        al[u].push_back({v,w});
        al[v].push_back({u,w});
    }
    
    vector<int> vis(n + 1, 0), dist(n + 1, INT_MAX);
    
    dist[1] = 0;
    priority_queue<pii,vector<pii>,cmp> pq;
    
    pq.push({1,0});
    
    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();
        
        int curr = p.first, currd = p.second;
        if(vis[curr]){
            continue;
        }
        vis[curr] = 1;
        
        for(int i = 0; i < al[curr].size(); i++){
            int child = al[curr][i].first, d = al[curr][i].second;
            if(vis[child] == 0 && d < dist[child]){
                dist[child] = d;
                pq.push({child, d});
            }
        }
    }
    int minCost = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX){
            return -1;
        }
        minCost += dist[i];
    }
    return minCost;
}
