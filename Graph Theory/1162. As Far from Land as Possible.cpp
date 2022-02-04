//Multisource BFS
class Solution {
public:
    #define pii pair<int,int>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int maxDistance(vector<vector<int>>& grid) {
        
        bool flag1 = false, flag2 = false;
        int m = grid.size(), n = grid[0].size();
        
        queue<pii> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    dist[i][j] = 0;
                    flag1 = true;
                    q.push({i,j});
                }
                if(!grid[i][j]){
                    flag2 = true;
                }
            }
        }
        if(!flag1 || !flag2){
            return -1;
        }
        
        while(!q.empty()){
            pii p = q.front();
            int x = p.first, y = p.second;            
            q.pop();

            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                    if(dist[xo][yo] > dist[x][y] + 1){
                        dist[xo][yo] = dist[x][y] + 1;
                        q.push({xo,yo});
                    }
                }
            }
        }
        
        int maxDist = INT_MIN;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // cout << dist[i][j] << " ";
                maxDist = max(maxDist, dist[i][j]);
            }
            // cout << endl;
        }
        return maxDist;
    }
};
