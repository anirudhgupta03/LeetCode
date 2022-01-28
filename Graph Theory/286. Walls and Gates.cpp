class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void wallsAndGates(vector<vector<int>> &rooms) {
        
        int m = rooms.size(), n = rooms[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[i].size(); j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> vis(m, vector<int>(n, 0));
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            int x = p.first, y = p.second;
            if(vis[x][y]) continue;

            vis[x][y] = 1;

            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                    if(vis[xo][yo] == 0 && rooms[x][y] + 1 < rooms[xo][yo]){
                        rooms[xo][yo] = rooms[x][y] + 1;
                        q.push({xo,yo});
                    }
                }
            }
        }
    }
};
