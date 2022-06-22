//Method - 1
//Using Bellman Ford Algorithm
//Ref: https://www.youtube.com/watch?v=5eIK3zUdYmE
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        
        for(int i = 0; i <= k; i++){
            vector<int> tempprice = prices;
            for(int j = 0; j < flights.size(); j++){
                int a = flights[j][0], b = flights[j][1], w = flights[j][2];
                if(prices[a] != INT_MAX && prices[a] + w < tempprice[b]){
                    tempprice[b] = prices[a] + w;
                }
            }
            prices = tempprice;
        }
        if(prices[dst] == INT_MAX){
            return -1;
        }
        return prices[dst];
    }
};

//Method - 2
//Using Dijkstra's Algorithm
class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    struct cmp{
      bool operator()(pipii &p1, pipii &p2){
          return p1.second.second > p2.second.second;
      }  
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> al[n];
        
        for(auto &x: flights){
            al[x[0]].push_back({x[1], x[2]});
        }
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        pq.push({src,{-1,0}});
        
        set<pipii> vis;
        
        while(!pq.empty()){
            
            int curr = pq.top().first, stops = pq.top().second.first, cost = pq.top().second.second;
            pq.pop();
            
            if(curr == dst){
                return cost;
            }
            
            if(vis.find({curr,{stops, cost}}) != vis.end()) continue;
            vis.insert({curr,{stops, cost}});
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i].first;
                
                if(stops + 1 <= k){
                    pq.push({child,{stops + 1, cost + al[curr][i].second}});
                }
            }
        }
        return -1;
    }
};
