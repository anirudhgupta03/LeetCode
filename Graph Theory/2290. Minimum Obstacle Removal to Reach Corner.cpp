//Dijkstra's Algorithm
class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    struct cmp{
      bool operator()(pipii &p1, pipii &p2){
          return p1.first > p2.first;
      }  
    };
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            
            int cost = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            if(x == m - 1 && y == n - 1){
                return cost;
            }
            if(vis[x][y]) continue;
            
            vis[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int newx = x + dx[i], newy = y + dy[i];
                if(newx >= 0 && newy >= 0 && newx < m && newy < n){
                    if(vis[newx][newy] == 0){
                        pq.push({cost + grid[newx][newy],{newx, newy}});
                    }
                }
            }
        }
        return 0;
    }
};
