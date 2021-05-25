class Solution {
public:
    #define pii pair<int,int>
    void dijkstra(int src, vector<int> &temp, int n, int distanceThreshold, vector<pair<int,int>> al[]){
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        pq.push({0,src});
        
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        
        vector<int> vis(n,0);
        
        while(!pq.empty()){
            
            int curr = pq.top().second, curr_d = pq.top().first;
            
            pq.pop();
            
            if(vis[curr]) continue;
            
            vis[curr] = 1;
            
            for(int i = 0; i < al[curr].size(); i++){
                
                int child = al[curr][i].first, d = al[curr][i].second;
                
                if(vis[child] == 0 && curr_d + d < dist[child]){
                    dist[child] = curr_d + d;
                    pq.push({dist[child],child});
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i == src) continue;
            if(dist[i] <= distanceThreshold){
                temp.push_back(i);
            }
        }
        
        
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>> al[n];
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            al[u].push_back({v,w});
            al[v].push_back({u,w});
        }
        
        int ans = INT_MAX;
        int id; 
        
        for(int i = 0; i < n; i++){
            
            vector<int> temp;
            
            dijkstra(i,temp,n,distanceThreshold,al);
            
            if(temp.size() <= ans){
                ans = temp.size();
                id = i;
            }
        }
        return id;
    }
};
