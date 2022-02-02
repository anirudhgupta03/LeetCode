class Solution {
public:
    #define pii pair<int,int>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int m = land.size(), n = land[0].size();
        
        vector<vector<int>> res;
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(land[i][j] == 1 && vis[i][j] == 0){
                    int sx = i, sy = j, ex = i, ey = j;
                    
                    queue<pii> q;
                    q.push({i,j});
                    
                    while(!q.empty()){
                        int sz = q.size();
                        while(sz--){
                            pii p = q.front();
                            q.pop();
                            
                            int x = p.first, y = p.second;
                            
                            if(x >= ex && y >= ey){
                                ex = x;
                                ey = y;
                            }
                            if(vis[x][y]) continue;
                            vis[x][y] = 1;
                            
                            for(int i = 0; i < 4; i++){
                                int xo = x + dx[i], yo = y + dy[i];
                                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                                    if(vis[xo][yo] == 0 && land[xo][yo] == 1){
                                        q.push({xo, yo});
                                    }
                                }
                            }
                        }
                    }
                    vector<int> temp = {sx,sy,ex,ey};
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
