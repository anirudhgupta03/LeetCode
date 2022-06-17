//Multi-Source BFS
//https://www.lintcode.com/problem/663/
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
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){

            int x = q.front().first, y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n && rooms[xo][yo] != -1){
                    if(rooms[x][y] + 1 < rooms[xo][yo]){
                        rooms[xo][yo] = rooms[x][y] + 1;
                        q.push({xo, yo});
                    }
                }
            }
        }
    }
};
