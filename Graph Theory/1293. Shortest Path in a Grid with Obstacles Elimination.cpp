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
