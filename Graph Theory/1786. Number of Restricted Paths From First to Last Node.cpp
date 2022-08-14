//Ref: https://www.youtube.com/watch?v=-wNfD38uYJU
//Method - 1
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

//Method - 2
class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    #define pii pair<int,int>
    #define mod 1000000007
    #define ll long long
    struct cmp{
      bool operator()(pii &p1, pii &p2){
          return p1.second > p2.second;
      }  
    };
    ll dfs(int node, int par, vector<pair<int,int>> al[], vector<int> &dist, vector<ll> &dp){
        
        if(node == dist.size() - 1){
            return 1;
        }
        if(dp[node] != -1){
            return dp[node];
        }
        ll count = 0;
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i].first;
            if(child != par && dist[child] < dist[node]){
                count = (count + dfs(child, node, al, dist, dp)) % mod;
            }
        }
        return dp[node] = count;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> al[n + 1];
        
        for(auto &x: edges){
            al[x[0]].push_back({x[1], x[2]});
            al[x[1]].push_back({x[0], x[2]});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push({n, 0});
        dist[n] = 0;
        
        while(!pq.empty()){
            
            int curr = pq.top().first, distance = pq.top().second;
            pq.pop();
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i].first, d = al[curr][i].second;
                if(dist[curr] + d < dist[child]){
                    dist[child] = dist[curr] + d;
                    pq.push({child, dist[child]});
                }
            }
        }
        vector<ll> dp(n + 1, -1);
        return dfs(1, -1, al, dist, dp);
    }
};

//Method
//Dijkstra + DP
class Solution {
public:
    #define pii pair<int,int>
    #define ll long long
    #define mod 1000000007
    struct cmp{
      bool operator()(pii &p1, pii &p2){
          return p1.second > p2.second;
      }  
    };
    ll solve(int curr, int n, vector<int> &dist, vector<pii> al[], vector<ll> &dp){
        
        if(curr == n){
            return 1;
        }
        if(dp[curr] != -1){
            return dp[curr];
        }
        ll count = 0;
        for(auto &x: al[curr]){
            if(dist[x.first] < dist[curr]){
                count = (count + solve(x.first, n, dist, al, dp))%mod;
            }
        }
        return dp[curr] = count;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<int> dist(n + 1, INT_MAX);
        
        vector<pii> al[n + 1];
        
        for(auto &x: edges){
            al[x[0]].push_back({x[1], x[2]});
            al[x[1]].push_back({x[0], x[2]});
        }
        
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push({n, 0});
        
        vector<int> vis(n + 1, 0);
        
        while(!pq.empty()){
            
            int curr = pq.top().first, d = pq.top().second;
            pq.pop();
            
            if(vis[curr]) continue;
            vis[curr] = 1;
            dist[curr] = d;
            
            for(auto &x: al[curr]){
                if(vis[x.first] == 0){
                    pq.push({x.first, d + x.second});
                }
            }
        }
        vector<ll> dp(n + 1, -1);
        return solve(1, n, dist, al, dp);
    }
};
