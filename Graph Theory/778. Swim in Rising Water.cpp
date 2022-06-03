//Path With Minimum Maximum Value
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define pipii pair<int,pair<int,int>>
    struct cmp{
        bool operator()(pipii p1, pipii p2){
            return p1.first > p2.first;
        }
    };
    int swimInWater(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        
        pq.push({grid[0][0],{0,0}});
        
        int ans = INT_MIN;
        
        while(!pq.empty()){
            
            int currval = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            ans = max(ans, currval);
            
            if(x == m - 1 && y == n - 1){
                return ans;
            }
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                    if(vis[xo][yo] == 0){
                        vis[xo][yo] = 1;
                        pq.push({grid[xo][yo],{xo,yo}});
                    }
                }
            }
        }
        return -1;
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
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        pq.push({grid[0][0],{0,0}});
        
        while(!pq.empty()){
            
            int maxValueTillNow = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            if(x == n - 1 && y == n - 1){
                return maxValueTillNow;
            }
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                
                if(xo >= 0 && yo >= 0 && xo < n && yo < n && vis[xo][yo] == 0){
                    pq.push({max(maxValueTillNow, grid[xo][yo]), {xo, yo}});
                }
            }
        }
        return 0;
    }
};
