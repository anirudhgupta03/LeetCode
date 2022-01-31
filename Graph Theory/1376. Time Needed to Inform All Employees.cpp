class Solution {
public:
    #define pii pair<int,int>
    struct cmp{
      bool operator()(pii p1, pii p2){
          return p1.second > p2.second;
      }  
    };
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<pair<int,int>> al[n];
        
        for(int i = 0; i < manager.size(); i++){
            if(manager[i] == -1) continue;
            int a = manager[i], b = i;
            al[a].push_back({b,informTime[a]});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[headID] = 0;
        
        vector<int> vis(n, 0);
        
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push({headID,0});
        
        int minTime = 0;
        while(!pq.empty()){
            pii p = pq.top();
            pq.pop();
            
            int curr = p.first, tempt = p.second;
            if(vis[curr]) continue;
            vis[curr] = 1;
            
            minTime = max(minTime, tempt);
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i].first;
                if(vis[child] == 0 && dist[curr] + al[curr][i].second < dist[child]){
                    dist[child] = dist[curr] + al[curr][i].second;
                    pq.push({child, dist[child]});
                }
            }
        }
        return minTime;
    }
};
