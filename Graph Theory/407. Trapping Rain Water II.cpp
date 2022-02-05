//Ref: https://www.youtube.com/watch?v=QvQiQcLCQ4Y
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
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<pipii, vector<pipii>, cmp> pq;
        
        int waterTrapped = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }
        
        int minBdht = 0;
        
        while(!pq.empty()){
            
            pipii p = pq.top();
            pq.pop();
            
            int currht = p.first, x = p.second.first, y = p.second.second;
            minBdht = max(minBdht, currht);
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                    if(vis[xo][yo] == 0){
                        vis[xo][yo] = 1;
                        pq.push({heightMap[xo][yo],{xo, yo}});
                        if(heightMap[xo][yo] < minBdht){
                            waterTrapped += minBdht - heightMap[xo][yo];
                        }
                    }
                }
            }
        }
        return waterTrapped;
    }
};
