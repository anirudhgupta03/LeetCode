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
