//Dijkstra
class Solution {
public:
    #define pipii pair<int,pair<int,int>>   //<dist,<row,col>>
    struct cmp{
      bool operator()(pipii p1, pipii p2){
          return p1.first > p2.first;
      }  
    };
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            
            int dist = pq.top().first, row = pq.top().second.first, col = pq.top().second.second;
            pq.pop();
            
            if(effort[row][col] < dist){
                continue;
            }
            
            if(row == m - 1 && col == n - 1) return dist;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + dx[i], ncol = col + dy[i];
                
                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n){
                    int newDist = max(dist, abs(heights[nrow][ncol] - heights[row][col]));
                    
                    if(newDist < effort[nrow][ncol]){
                        effort[nrow][ncol] = newDist;
                        pq.push({newDist, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

//Method - 2
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size(), n = heights[0].size();
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        
        pq.push({0,{0,0}});
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        while(!pq.empty()){
            
            int diff = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            if(x == m - 1 && y == n - 1){
                return diff;
            }
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n && vis[xo][yo] == 0){
                    pq.push({max(diff, abs(heights[xo][yo] - heights[x][y])),{xo,yo}});
                }
            }
        }
        return 0;
    }
};
