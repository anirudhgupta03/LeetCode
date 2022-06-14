class Solution {
public:
    #define pid pair<int,double>
    struct cmp{
      bool operator()(pid &p1, pid &p2){
          return p1.second < p2.second;
      }  
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pid> al[n];
        
        for(int i = 0; i < edges.size(); i++){
            al[edges[i][0]].push_back({edges[i][1], succProb[i]});
            al[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pid, vector<pid>, cmp> pq;
        pq.push({start, 1.0});
        
        vector<int> vis(n, 0);
        
        while(!pq.empty()){
            
            int curr = pq.top().first;
            double prob = pq.top().second;
            
            pq.pop();
            
            if(curr == end){
                return prob;
            }
            
            if(vis[curr]) continue;
            vis[curr] = 1;
            
            for(int i = 0; i < al[curr].size(); i++){
                if(vis[al[curr][i].first] == 0){
                    pq.push({al[curr][i].first, prob*al[curr][i].second});
                }
            }
        }
        return 0;
    }
};
