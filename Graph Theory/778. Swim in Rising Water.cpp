//Method - 1
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

//Method - 2
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int t = x[0], i = x[1], j = x[2];
            if(i == n - 1 && j == n - 1){
                return t;
            }
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(int dir = 0; dir < 4; dir++){
                int di = i + dx[dir], dj = j + dy[dir];
                if(di >= 0 && dj >= 0 && di < n && dj < n && !vis[di][dj]){
                    pq.push({max(grid[di][dj], t), di, dj});
                }
            }
        }
        return -1;
    }
};
