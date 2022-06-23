//DFS + Hashing
class Solution {
public:
    #define pii pair<int,int>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<pair<int,int>> &path, vector<vector<int>> &grid, int &count, vector<vector<int>> &vis){
        
        path.push_back({x,y});
        vis[x][y] = 1;
        count++;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size()){
                if(grid[xo][yo] == 1 && vis[xo][yo] == 0){
                    dfs(xo, yo, path, grid, count, vis);
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        map<pii,pii> mp;
        
        int n = grid.size();
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        vector<vector<pair<int,int>>> mat(n, vector<pair<int,int>>(n));
        
        int id = 1;
        int maxSize = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int count = 0;
                    vector<pair<int,int>> path;
                    dfs(i, j, path, grid, count, vis);
                    for(int k = 0; k < path.size(); k++){
                        mat[path[k].first][path[k].second] = {id, count};
                    }
                    maxSize = max(maxSize, count);
                    id++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> us;
                    int size = 0;
                    for(int k = 0; k < 4; k++){
                        int io = i + dx[k], jo = j + dy[k];
                        if(io >= 0 && jo >= 0 && io < n && jo < n){
                            if(grid[io][jo] == 1){
                                int tid = mat[io][jo].first;
                                if(us.find(tid) == us.end()){
                                    us.insert(tid);
                                    size += mat[io][jo].second;
                                }
                            }
                        }
                    }
                    maxSize = max(maxSize, size + 1);
                }
            }
        }
        return maxSize;
    }
};

//Alternate
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<pair<int,int>> &path, int &count, vector<vector<int>> &grid, vector<vector<int>> &vis){
        
        path.push_back({x,y});
        vis[x][y] = 1;
        count++;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && xo < grid.size() && yo >= 0 && yo < grid[0].size()){
                if(grid[xo][yo] == 1 && vis[xo][yo] == 0){
                    dfs(xo, yo, path, count, grid, vis);
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<int> par(n*n);
        
        for(int i = 0; i < n*n; i++){
            par[i] = i;
        }
        
        vector<int> sz(n*n, 0), rank(n*n, 0);
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int count = 0, cell = n*i + j;
                    vector<pair<int,int>> path;
                    dfs(i,j,path,count,grid,vis);
                    for(int k = 0; k < path.size(); k++){
                        int x = path[k].first, y = path[k].second;
                        int cellk = n*x + y;
                        par[cellk] = cell;
                        sz[cellk] = count;
                    }
                    rank[cell] = 1;
                }
            }
        }
        
        vector<int> temppar = par, temprank = rank;
        
        int maxSize = 1;
        
        for(int i = 0; i < n*n; i++){
            maxSize = max(maxSize, sz[i]);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int size = 0;
                    bool flag = false;
                    unordered_set<int> us;
                    for(int k = 0; k < 4; k++){
                        int io = i + dx[k], jo = j + dy[k];
                        if(io >= 0 && jo >= 0 && io < n && jo < n){
                            if(grid[io][jo] == 1){
                                int cell = n*io + jo;
                                int parcell = par[cell];
                                if(us.find(parcell) == us.end()){
                                    us.insert(parcell);
                                    size += sz[parcell];
                                }
                            }
                        }
                    }
                    maxSize = max(maxSize, size + 1);
                }
            }
        }
        return maxSize;
    }
};

//Union-Find
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int abparent, int x, int y, int n, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &par, int &count){
        
        par[n*x + y] = abparent;
        vis[x][y] = 1;
        count++;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < n && yo < n && vis[xo][yo] == 0 && grid[xo][yo]){
                dfs(abparent, xo, yo, n, grid, vis, par, count);
            }
        }
    }
    
    int findP(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return findP(par[node], par);
    }
    
    void unionP(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<int> par(n*n), size(n*n, 0);
        
        for(int i = 0; i < n*n; i++){
            par[i] = i;
        }
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int count = 0;
                    dfs(n*i + j, i, j, n, grid, vis, par, count);
                    size[n*i + j] = count;
                }
            }
        }
        
        int largestSize = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j] == 0){
                    
                    int count = 1;
                    int parc = par[n*i + j];
                    vector<int> temp(4,-1);
                    
                    for(int k = 0; k < 4; k++){
                        int io = i + dx[k], jo = j + dy[k];
                        if(io >= 0 && jo >= 0 && io < n && jo < n && grid[io][jo]){
                            int park = findP(n*io + jo, par);
                            temp[k] = park;
                            if(park != parc){
                                count += size[park];
                                unionP(parc, park, par);
                            }
                        }
                    }
                    
                    largestSize = max(largestSize, count);
                    for(int k = 0; k < 4; k++){
                        if(temp[k] != -1){
                            par[temp[k]] = temp[k];
                        }
                    }
                }
            }
        }
        return largestSize == 0 ? n*n : largestSize;
    }
};
