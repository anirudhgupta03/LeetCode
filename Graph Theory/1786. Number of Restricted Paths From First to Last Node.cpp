//Ref: https://www.youtube.com/watch?v=-wNfD38uYJU
class Solution {
public:
    #define ll long long
    #define pll pair<ll,ll>
    #define plvl pair<ll,vector<ll>>
    struct cmp{
      bool operator()(pll p1, pll p2){
          return p1.second > p2.second;
      }  
    };
    
    int mod = 1e9 + 7;
    
    ll solve(int node, int n, vector<ll> &dist, vector<ll> &vis, vector<pair<ll,ll>> al[], vector<ll> &dp){
        
        if(node == n){
            return 1;
        }
        
        if(dp[node] != -1){
            return dp[node];
        }
        
        ll count = 0;
        for(int i = 0; i < al[node].size(); i++){
            ll child = al[node][i].first;
            if(vis[child] == 0 && dist[child] < dist[node]){
                vis[child] = 1;
                count = (count + solve(child, n, dist, vis, al,dp))%mod;
                vis[child] = 0;
            }
        }
        return dp[node] = count%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<pair<ll,ll>> al[n + 1];
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            al[u].push_back({v,w});
            al[v].push_back({u,w});
        }
        
        vector<ll> dist(n + 1, LLONG_MAX), vis(n + 1, 0);
        dist[n] = 0;
        
        priority_queue<pll, vector<pll>, cmp> pq;
        pq.push({n,0});
        
        while(!pq.empty()){
            
            pll p = pq.top();
            pq.pop();
            
            ll curr = p.first, currd = p.second;
            
            if(vis[curr]){
                continue;
            }
            vis[curr] = 1;
            
            for(int i = 0; i < al[curr].size(); i++){
                ll child = al[curr][i].first, childw = al[curr][i].second;
                if(vis[child] == 0 && currd + childw < dist[child]){
                    dist[child] = currd + childw;
                    pq.push({child, dist[child]});
                }
            }
        }
      
        ll count = 0;
        for(int i = 1; i <= n; i++) vis[i] = 0;
        vis[1] = 1;
    
        vector<ll> dp(n + 1, -1);
        
        return solve(1, n, dist, vis, al, dp);
    }
};