//Method - 1
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> lr(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            if(mat[i][0] == 0) lr[i][0] = 0;
            else if(mat[i][0] == 1) lr[i][0] = INT_MAX;
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                if(mat[i][j] == 0){
                    lr[i][j] = 0;
                }
                else{
                    if(lr[i][j-1] == INT_MAX){
                        lr[i][j] = INT_MAX;
                    }
                    else{
                        lr[i][j] = lr[i][j-1] + 1;
                    }
                }
            }
        }
        
        vector<vector<int>> rl(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            if(mat[i][n - 1] == 0) rl[i][n - 1] = 0;
            else rl[i][n - 1] = INT_MAX;
        }
        
        for(int i = 0; i < m; i++){
            for(int j = n - 2; j >= 0; j--){
                if(mat[i][j] == 0){
                    rl[i][j] = 0;
                }
                else{
                    if(rl[i][j+1] == INT_MAX){
                        rl[i][j] = INT_MAX;
                    }
                    else{
                        rl[i][j] = rl[i][j+1] + 1;
                    }
                }
            }
        }
        
        //Top to bottom
        for(int j = 0; j < n; j++){
            for(int i = 1; i < m; i++){
                if(lr[i-1][j] != INT_MAX) lr[i][j] = min(lr[i][j], lr[i-1][j] + 1);
            }
        }
        
        //Bottom to top
        for(int j = 0; j < n; j++){
            for(int i = m - 2; i >= 0; i--){
                if(lr[i+1][j] != INT_MAX) lr[i][j] = min(lr[i][j], lr[i+1][j] + 1);
            }
        }
        
        //Top to bottom
        for(int j = 0; j < n; j++){
            for(int i = 1; i < m; i++){
                if(rl[i-1][j] != INT_MAX) rl[i][j] = min(rl[i][j], rl[i-1][j] + 1);
            }
        }
        
        //Bottom to top
        for(int j = 0; j < n; j++){
            for(int i = m - 2; i >= 0; i--){
                if(rl[i+1][j] != INT_MAX) rl[i][j] = min(rl[i][j], rl[i+1][j] + 1);
            }
        }
        
        vector<vector<int>> res(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res[i][j] = min(lr[i][j], rl[i][j]);
            }
        }
        return res;
    }
};

//Method - 2
//Multi-Source BFS
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define pii pair<int,int>
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        queue<pii> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                
                if(xo >= 0 && xo < m && yo >= 0 && yo < n){
                    if(dist[x][y] + 1 < dist[xo][yo]){
                        dist[xo][yo] = dist[x][y] + 1;
                        q.push({xo, yo});
                    }
                }
            }
        }
        return dist;
    }
};
