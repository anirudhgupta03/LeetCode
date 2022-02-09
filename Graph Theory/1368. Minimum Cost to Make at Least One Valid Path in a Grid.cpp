//Dijkstra
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int dir[4] = {4,3,2,1};
    #define pipii pair<int,pair<int,int>>
    struct cmp{
        bool operator()(pipii &p1, pipii &p2){
            return p1.first > p2.first;
        }
    };
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        pq.push({0,{0,0}});
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        while(!pq.empty()){
            
            int cost = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            if(x == m - 1 && y == n - 1){
                return cost;
            }
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                    if(vis[xo][yo] == 0){
                        if(grid[x][y] == dir[i]){
                            pq.push({cost,{xo,yo}});
                        }
                        else{
                            pq.push({cost + 1, {xo, yo}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
