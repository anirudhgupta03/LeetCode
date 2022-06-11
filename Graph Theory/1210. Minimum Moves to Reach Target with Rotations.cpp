//Method - 1
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

//Method - 2
class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    int minimumMoves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[n - 1][n - 2] || grid[n - 1][n - 1]){
            return -1;
        }
        
        int steps = 0;
        
        queue<pipii> q;
        q.push({0,{0,0}});
        
        int vis[2][n][n];
        memset(vis,0,sizeof(vis));
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                int dir = q.front().first, tailx = q.front().second.first, taily = q.front().second.second;
                int headx, heady;
                
                if(dir == 0){
                    headx = tailx;
                    heady = taily + 1;
                }
                else{
                    heady = taily;
                    headx = tailx + 1;
                }
                
                q.pop();
                
                if(tailx == n - 1 && taily == n - 2 && headx == n - 1 && heady == n - 1){
                    return steps;
                }
                
                if(vis[dir][tailx][taily]) continue;
                vis[dir][tailx][taily] = 1;
                
                if(heady + 1 < n){
                    if(vis[dir][tailx][taily + 1] == 0 && grid[tailx][taily + 1] == 0 && grid[headx][heady + 1] == 0){
                        q.push({dir,{tailx, taily + 1}});
                    }
                }
                if(headx + 1 < n){ 
                    if(vis[dir][tailx + 1][taily] == 0 && grid[tailx + 1][taily] == 0 && grid[headx + 1][heady] == 0){
                        q.push({dir,{tailx + 1, taily}});
                    }
                }
                if(headx == tailx){
                    if(headx + 1 < n && vis[1 - dir][tailx][taily] == 0 && grid[headx + 1][taily] == 0 && grid[headx + 1][heady] == 0){
                        q.push({1 - dir,{tailx, taily}});
                    }
                }
                if(heady == taily){
                    if(heady + 1 < n && vis[1 - dir][taily][tailx] == 0 && grid[headx][taily + 1] == 0 && grid[tailx][taily + 1] == 0){
                        q.push({1 - dir,{tailx, taily}});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
