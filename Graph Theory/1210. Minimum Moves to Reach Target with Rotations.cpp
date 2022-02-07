class Solution {
public:
    #define pii pair<int,int>
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    int minimumMoves(vector<vector<int>>& grid) {
        
        queue<pair<pii,pii>> q;
        q.push({{0,0},{0,1}});
        
        int n = grid.size();
        
        set<pair<pii,pii>> vis;
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<pii,pii> p = q.front();
                q.pop();
        
                int x1 = p.first.first, y1 = p.first.second;
                int x2 = p.second.first, y2 = p.second.second;
                
                if(x1 == n - 1 && y1 == n - 2 && x2 == n - 1 && y2 == n - 1){
                    return steps;
                }
                
                if(vis.find({{x1,y1},{x2,y2}}) != vis.end()) continue;
                vis.insert({{x1,y1},{x2,y2}});
                
                for(int i = 0; i < 2; i++){
                    int x1o = x1 + dx[i], y1o = y1 + dy[i];
                    int x2o = x2 + dx[i], y2o = y2 + dy[i];
                    if(x1o < n && y1o < n && x2o < n && y2o < n){
                        if(vis.find({{x1o,y1o},{x2o,y2o}}) == vis.end() && grid[x1o][y1o] == 0 && grid[x2o][y2o] == 0){
                            q.push({{x1o,y1o},{x2o,y2o}});
                        }
                    }
                }
                
                if(x1 == x2 && y2 - y1 == 1){
                    if(x1 + 1 < n && grid[x1 + 1][y1] == 0 && grid[x1 + 1][y2] == 0){
                        if(vis.find({{x1,y1},{x1+1,y1}}) == vis.end()){
                            q.push({{x1,y1},{x1+1,y1}});
                        }
                    }
                }
                
                if(x2 - x1 == 1 && y1 == y2){
                    if(y1 + 1 < n && grid[x1][y1 + 1] == 0 && grid[x2][y2 + 1] == 0){
                        if(vis.find({{x1,y1},{x1,y1+1}}) == vis.end()){
                            q.push({{x1,y1},{x1,y1+1}});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
