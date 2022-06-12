//Method - 1
class Solution {
public:
    #define ppiipii pair<pair<int,int>,pair<int,int>>
    struct cmp{
      bool operator()(ppiipii &p1, ppiipii &p2){
          return p1.second.first > p2.second.first;
      }  
    };
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<ppiipii, vector<ppiipii>, cmp> pq;
        
        pq.push({{0,0},{0,0}});
        
        set<pair<pair<int,int>,int>> vis;
        
        int minSteps = INT_MAX;
        
        while(!pq.empty()){
            
            ppiipii p = pq.top();
            pq.pop();
            
            int x = p.first.first, y = p.first.second, steps = p.second.first, obstacles = p.second.second;
            
            if(x == m - 1 && y == n - 1){
                return steps;
            }
            
            if(vis.find({{x,y}, obstacles}) != vis.end()) continue;
            vis.insert({{x,y}, obstacles});
            
            for(int i  = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                        if(grid[xo][yo] == 0){
                            if(vis.find({{xo,yo}, obstacles}) == vis.end()){
                                pq.push({{xo,yo},{steps + 1, obstacles}});
                            }
                        }
                        else{
                            if(obstacles + 1 <= k){
                                if(vis.find({{xo,yo}, obstacles + 1}) == vis.end()){
                                    pq.push({{xo,yo},{steps + 1, obstacles + 1}});
                                }
                            }
                        }
                }
            }
        }
        return -1;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=ID9YJXy3OJk
class Solution {
public:
    #define pii pair<int,int>
    #define ppp pair<pii,pii>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    struct cmp{
      bool operator()(ppp &p1, ppp &p2){
          return p1.first.first > p2.first.first;
      }  
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<ppp, vector<ppp>, cmp> pq;
        
        pq.push({{0,0},{0,0}});
        
        int vis[m][n][k + 1];
        memset(vis,0,sizeof(vis));
        
        while(!pq.empty()){
            
            int steps = pq.top().first.first, count = pq.top().first.second;
            int x = pq.top().second.first, y = pq.top().second.second;
            
            pq.pop();
            
            if(x == m - 1 && y == n - 1){
                return steps;
            }
            
            if(vis[x][y][count]) continue;
            vis[x][y][count] = 1;
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                
                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                    if(grid[xo][yo] == 0 && vis[xo][yo][count] == 0){
                        pq.push({{steps + 1, count},{xo, yo}});
                    }
                    else if(count + 1 <= k && vis[xo][yo][count + 1] == 0){
                            pq.push({{steps + 1, count + 1},{xo, yo}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
