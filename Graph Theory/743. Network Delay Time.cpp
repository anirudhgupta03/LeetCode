//Using Dijkstra
//Method - 1
class Solution {
public:
    #define pii pair<int,int>
    struct cmp{
        bool operator()(pii p1, pii p2){
            return p1.second > p2.second;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> al[n + 1];
        
        for(int i = 0; i < times.size(); i++){
            int a = times[i][0], b = times[i][1], w = times[i][2];
            al[a].push_back({b,w});
        }
        
        vector<int> vis(n + 1, 0);
        vector<int> timetaken(n + 1, INT_MAX);
        
        timetaken[k] = 0;
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push({k,0});
        
        while(!pq.empty()){
            
            pii p = pq.top();
            pq.pop();
            
            int node = p.first, ttime = p.second;
            
            if(vis[node]){
                continue;
            }
            vis[node] = 1;
            
            for(int i = 0; i < al[node].size(); i++){
                int child = al[node][i].first, tempt = al[node][i].second;
                if(vis[child] == 0 && ttime + tempt < timetaken[child]){
                    pq.push({child,ttime + tempt});
                    timetaken[child] = ttime + tempt;
                }
            }
        }
        
        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(timetaken[i] == INT_MAX){
                return -1;
            }
            maxTime = max(maxTime, timetaken[i]);
        }
        return maxTime;
    }
};

//Method - 2 
class Solution {
public:
    #define pii pair<int,int>
    struct cmp{
      bool operator()(pii &p1, pii &p2){
          return p1.second > p2.second;
      }  
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pii, vector<pii>, cmp> pq;
        
        pq.push({k, 0});
        
        vector<pii> al[n + 1];
        
        for(auto &x: times){
            al[x[0]].push_back({x[1], x[2]});
        }
        
        vector<int> vis(n + 1, 0);
        int minTime = 0;
        
        while(!pq.empty()){
            
            int curr = pq.top().first, timetaken = pq.top().second;
            pq.pop();
            
            if(vis[curr]) continue;
            vis[curr] = 1;
            
            minTime = max(minTime, timetaken);
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i].first, t = al[curr][i].second;
                if(vis[child] == 0){
                    pq.push({child, timetaken + t});
                }
            }
        }
        
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0) return -1;
        }
        return minTime;
    }
};
