class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool isPossibleToReach(vector<vector<int>> &ngrid, int m, int n){
        
        queue<pair<int,int>> person, fire;
        unordered_map<int,int> umap;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ngrid[i][j] == 1){
                    fire.push({i, j});
                    umap[n*i + j] = 1;
                }
            }
        }
        person.push({0, 0});
        
        while(!person.empty() || !fire.empty()){
            int sz = fire.size();
            while(sz--){
                pair<int,int> p = fire.front();
                fire.pop();
                int x = p.first, y = p.second;
                umap[x*n + y] = 1;
                ngrid[x][y] = 1;
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                        if(ngrid[nx][ny] == 0 || ngrid[nx][ny] == 3){
                            fire.push({nx, ny});
                        }
                    }
                }
            }

            sz = person.size();
            while(sz--){
                pair<int,int> p = person.front();
                person.pop();
                int x = p.first, y = p.second;
                if(x == m - 1 && y == n - 1){
                    return true;
                }
                if(umap.find(n*x + y) == umap.end()){
                    if(x >= 0 && y >= 0 && x < m && y < n)
                    ngrid[x][y] = 3;
                    for(int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                            if(ngrid[nx][ny] == 0){
                                person.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
    bool minsStayed(int minsStayed, vector<vector<int>> &grid, int m, int n){
        
        vector<vector<int>> ngrid = grid;
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty() && minsStayed >= 0){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                ngrid[x][y] = 1;
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                        if(ngrid[nx][ny] == 0){
                            q.push({nx, ny});
                        }
                    }
                }
            }
            minsStayed--;
        }

        if(ngrid[0][0] == 1 || ngrid[m - 1][n - 1] == 1){
            return false;
        }
        return isPossibleToReach(ngrid, m, n);
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int lo = 0, hi = 1e9;
        int ans = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(minsStayed(mid, grid, m, n)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
