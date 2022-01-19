class Solution {
public:
    #define pipii pair<pair<int,int>,int>
    bool static cmp(pipii p1, pipii p2){
        return p1.second < p2.second;
    }
    int findp(int node, vector<int> &par){
        if(par[node] == -1){
            return node;
        }
        return par[node] = findp(par[node], par);
    }
    void unionp(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        vector<pipii> edges;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int manhattenDistance = abs(x1 - x2) + abs(y1 - y2);
                edges.push_back({{i,j}, manhattenDistance});
            }
        }
        
        sort(edges.begin(), edges.end(), cmp);
        int minCost = 0;
        
        vector<int> par(n, -1);
        
        for(int i = 0; i < edges.size(); i++){
            
            int u = edges[i].first.first, v = edges[i].first.second;
            
            int paru = findp(u, par);
            int parv = findp(v, par);
            
            if(paru != parv){
                minCost += edges[i].second;
                unionp(paru, parv, par);
            }
        }
        return minCost;
    }
};
