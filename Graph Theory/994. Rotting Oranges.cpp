//Ref: https://www.youtube.com/watch?v=Dq3dGS_0Z6o
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int,int>> q;
        
        bool flag = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    flag = true;
                }
            }
        }
        
        if(!flag){      //No Fresh Oranges
            return 0;
        }
        int minTime = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for(int i = 0; i < 4; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                        if(grid[xo][yo] == 1){
                            grid[xo][yo] = 2;
                            q.push({xo, yo});
                        }
                    }
                }
            }
            minTime++;
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minTime - 1;
    }
};
