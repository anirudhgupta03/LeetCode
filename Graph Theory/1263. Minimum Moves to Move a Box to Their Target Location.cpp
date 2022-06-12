//Method - 1
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define pii pair<int,int>
    #define vvi vector<vector<char>>
    bool isPossible(int srcx, int srcy, int dstx, int dsty, vector<vector<char>> &grid){
        
        queue<pair<int,int>> q;
        q.push({srcx, srcy});
        
        int m = grid.size(), n = grid[0].size();
        
        int vis[m][n];
        memset(vis,0,sizeof(vis));
        
        while(!q.empty()){
            pii p = q.front();
            q.pop();
            
            int x = p.first, y = p.second;
            
            if(x == dstx && y == dsty){
                return true;
            }
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size()){
                    if(grid[xo][yo] != '#' && grid[xo][yo] != 'B' && vis[xo][yo] == 0){
                        q.push({xo,yo});
                    }
                }
            }
        }
        return false;
    }
    int minPushBox(vector<vector<char>>& grid) {
        
        pii p1, p2;
        
        int m = grid.size(), n = grid[0].size(), dstx, dsty;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'B'){
                    p1 = {i, j};
                }
                if(grid[i][j] == 'S'){
                    p2 = {i, j};
                }
                if(grid[i][j] == 'T'){
                    dstx = i;
                    dsty = j;
                }
            }
        }
        
        int vis[m][n][m][n];
        memset(vis,0,sizeof(vis));
        
        int pushes = 0;
        
        queue<pair<pair<pii,pii>,vvi>> q;
        q.push({{p1,p2},grid});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<pii,pii> p = q.front().first;
                vvi curr = q.front().second;
                q.pop();
                
                
                int x1 = p.first.first, y1 = p.first.second;
                int x2 = p.second.first, y2 = p.second.second;
                
                if(x1 == dstx && y1 == dsty){
                    return pushes;
                }
                
                if(vis[x1][y1][x2][y2]) continue;
                vis[x1][y1][x2][y2] = 1;
                
                for(int i = 0; i < 4; i++){
                    int xo = x1 + dx[i], yo = y1 + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                        if(curr[xo][yo] != '#'){
                            if(isPossible(x2, y2, xo, yo, curr)){
                                int nxo = x1 - dx[i], nyo = y1 - dy[i];
                                if(nxo >= 0 && nyo >= 0 && nxo < m && nyo < n && curr[nxo][nyo] != '#' && vis[nxo][nyo][x1][y1] == 0){           
                                    char ch = curr[nxo][nyo];
                                    curr[x2][y2] = '.';
                                    curr[nxo][nyo] = 'B';
                                    curr[x1][y1] = 'S';
                                    q.push({{{nxo,nyo},{x1,y1}},curr});
                                    curr[nxo][nyo] = ch;
                                    curr[x2][y2] = 'S';
                                    curr[x1][y1] = 'B';
                                }
                            }
                        }
                    }
                }
            }
            pushes++;
        }
        return -1;
    }
};

//Method - 2
class Solution {
public:
    #define pii pair<int,int>
    #define pippp pair<int,pair<pii,pii>>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    struct cmp{
      bool operator()(pippp &p1, pippp &p2){
          return p1.first > p2.first;
      }  
    };
    int minPushBox(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<pippp, vector<pippp>, cmp> pq;
        int tx,ty,sx,sy,bx,by;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j] == 'B'){
                    bx = i;
                    by = j;
                }
                if(grid[i][j] == 'T'){
                    tx = i;
                    ty = j;
                }
            }
        }
        
        int vis[m][n][m][n];
        memset(vis, 0, sizeof(vis));
        
        pq.push({0,{{sx,sy},{bx,by}}});
        
        while(!pq.empty()){
            
            pippp p = pq.top();
            pq.pop();
            
            int count = p.first;
            sx = p.second.first.first, sy = p.second.first.second;
            bx = p.second.second.first, by = p.second.second.second;

            if(vis[sx][sy][bx][by]) continue;
            vis[sx][sy][bx][by] = 1;

            for(int i = 0; i < 4; i++){
                int sxo = sx + dx[i], syo = sy + dy[i];
                if(sxo >= 0 && syo >= 0 && sxo < m && syo < n){
                    if(sxo == bx && syo == by){
                        int bxo = sxo + dx[i], byo = syo + dy[i];
                        if(bxo >= 0 && byo >= 0 && bxo < m && byo < n && vis[sxo][syo][bxo][byo] == 0){
                            if(bxo == tx && byo == ty){
                                return count + 1;
                            }
                            else if(grid[bxo][byo] != '#'){
                                pq.push({count + 1,{{sxo,syo}, {bxo, byo}}});
                            }
                        }
                    }
                    else if(grid[sxo][syo] != '#' && vis[sxo][syo][bx][by] == 0){
                        pq.push({count,{{sxo,syo}, {bx, by}}});
                    }
                }
            }
        }
        return -1;
    }
};
