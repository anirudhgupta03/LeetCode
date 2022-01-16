//Dijkstra's Algo
class Solution {
public:
    #define pid pair<int, double>
    struct cmp{
      bool operator()(pid p1, pid p2){
          return p1.second < p2.second;
      }  
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        double maxProb = 0;
        
        vector<pair<int,double>> al[n];
        
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            al[a].push_back({b,succProb[i]});
            al[b].push_back({a,succProb[i]});
        }
        
        vector<int> vis(n, 0);
        
        priority_queue<pid, vector<pid>, cmp> pq;
        
        pq.push({start, -1});
        
        while(!pq.empty()){
            int curr = pq.top().first;
            double prob = pq.top().second;
            pq.pop();
            
            if(vis[curr]){
                continue;
            }
            vis[curr] = 1;
            
            if(curr == end){
                maxProb = prob;
            }
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i].first;
                if(vis[child] == 0){
                    if(prob == -1){
                        pq.push({child, al[curr][i].second});
                    }
                    else{
                        pq.push({child, prob*al[curr][i].second});
                    }
                }
            }
        }
        return maxProb;
    }
};
