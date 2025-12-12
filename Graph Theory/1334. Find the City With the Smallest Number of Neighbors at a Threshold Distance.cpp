#define pii pair<int,int>
class Solution {
public:
    int numberOfCitiesWithinThreshold(int src, int n, vector<pii> adj[], int distanceThreshold){

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> vis(n, 0);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
      
        int count = 0;
        while(!pq.empty()){
            auto[d, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            if(d <= distanceThreshold) count++;
            for(auto &[nbr, wt]: adj[node]){
                if(d + wt < dist[nbr]){
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>> adj[n];

        for(auto &edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int city = 0, cities = INT_MAX;
        for(int i = 0; i < n; i++){
            int res = numberOfCitiesWithinThreshold(i, n, adj, distanceThreshold);
            if(res <= cities){
                city = i;
                cities = res;
            }
        }
        return city;
    }
};
