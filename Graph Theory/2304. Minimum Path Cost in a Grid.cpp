class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    struct cmp{
      bool operator()(pipii &p1, pipii &p2){
          return p1.first > p2.first;
      }  
    };
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        
        int m = grid.size(), n = grid[0].size();
        
        for(int j = 0; j < n; j++){
            pq.push({grid[0][j],{0,j}});
        }
        
        int minCost = INT_MAX;
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        while(!pq.empty()){
            
            int cost = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            if(x == m - 1){
                minCost = min(minCost, cost);
                continue;
            }
            
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            
            for(int j = 0; j < n; j++){
                int xo = x + 1, yo = j;
                if(vis[xo][yo] == 0){
                    pq.push({cost + moveCost[grid[x][y]][yo] + grid[xo][yo],{xo, yo}});
                }
            }
        }
        return minCost;
    }
};
