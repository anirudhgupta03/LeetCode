//Dijkstra's Algo
//Ref: https://www.youtube.com/watch?v=rBmg3dg_MVc
#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = 1e9 + 7;

        vector<pair<int,int>> adj[n];

        for(auto &road: roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});

        vector<bool> vis(n, false);
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);

        ways[0] = 1;
        dist[0] = 0;
        while(!pq.empty()){
            auto[t, city] = pq.top();
            pq.pop();

            if(vis[city]) continue;
            vis[city] = true;

            for(auto &[ncity, timei]: adj[city]){
                if(t + timei < dist[ncity]){
                    dist[ncity] = t + timei;
                    ways[ncity] = ways[city];
                    pq.push({dist[ncity], ncity});
                }
                else if(t + timei == dist[ncity]){
                    ways[ncity] = (ways[ncity] + ways[city])%mod;
                }
            }
        }
        return ways[n - 1];
    }
};
