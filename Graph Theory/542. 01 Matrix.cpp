class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && mat[nx][ny] != 0){
                    if(dist[nx][ny] > dist[x][y] + 1){
                        dist[nx][ny] = 1 + dist[x][y];
                        q.push({nx, ny});
                    }
                }
            }
        }   
        return dist;
    }
};
