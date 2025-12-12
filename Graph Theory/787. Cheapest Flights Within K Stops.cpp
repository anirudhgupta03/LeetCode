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
#define ppi pair<pair<int,int>,int>
struct cmp{
    bool operator()(ppi &p1, ppi &p2){
        return p1.first.first > p2.first.first;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];

        for(auto &flight: flights){
            int source = flight[0], destination = flight[1], price = flight[2];
            adj[source].push_back({destination, price});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<ppi, vector<ppi>, cmp> pq;
        pq.push({{-1, 0},src});

        while(!pq.empty()){
            int stops = pq.top().first.first;
            int price = pq.top().first.second;
            int place = pq.top().second;
            pq.pop();
            for(auto &adjPlace: adj[place]){
                if(price + adjPlace.second < dist[adjPlace.first] && (stops + 1 <= k)){
                    dist[adjPlace.first] = price + adjPlace.second;
                    pq.push({{stops + 1, dist[adjPlace.first]}, adjPlace.first});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
