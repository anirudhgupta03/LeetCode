//Method - 1
//Gives TLE
class Solution {
public:
    #define pii pair<int,int>
    #define pipii pair<int,pair<int,int>>
    struct cmp{
      bool operator()(pipii &p1, pipii &p2){
          return p1.first > p2.first;
      }  
    };
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target){
            return 0;
        }
        unordered_map<int,vector<pii>> buses;
        
        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size() - 1; j++){
                buses[routes[i][j]].push_back({i, routes[i][j + 1]});
            }
            buses[routes[i][routes[i].size() - 1]].push_back({i, routes[i][0]});
        }
        
        set<pii> vis;
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        pq.push({0,{source,-1}});
        
        while(!pq.empty()){
            pipii p = pq.top();
            pq.pop();
            
            int count = p.first, curr = p.second.first, bus = p.second.second;
            
            if(curr == target){
                return count;
            }
            
            if(vis.find({bus, curr}) != vis.end()) continue;
            vis.insert({bus, curr});
            
            for(auto &x: buses[curr]){
                if(vis.find({x.first, x.second}) != vis.end()) continue;
                if(x.first == bus) pq.push({count, {x.second, x.first}});
                else               pq.push({count + 1,{x.second, x.first}});
            }
        }
        return -1;
    }
};

//Method - 2
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        unordered_map<int,vector<int>> busesInCity;

        for(int i = 0; i < routes.size(); i++){
            for(auto &city: routes[i]){
                busesInCity[city].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        unordered_map<int,bool> visBus, visBusStop;
        q.push({source, 0});
        visBusStop[source] = true;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[cityNo, busesTaken] = q.front();
                q.pop();

                if(cityNo == target) return busesTaken;

                for(auto &bus: busesInCity[cityNo]){
                    if(visBus[bus]) continue;
                    visBus[bus] = true;
                    for(auto &busStops: routes[bus]){
                        if(visBusStop[busStops]) continue;
                        q.push({busStops, busesTaken + 1});
                        visBusStop[busStops] = true;
                    }
                }
            }
        }
        return -1;
    }
};
