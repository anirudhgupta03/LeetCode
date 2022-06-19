//https://www.lintcode.com/problem/787/
//Ref: https://www.youtube.com/watch?v=mjDfgdGp-II
//Method - 1
class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool solve(int x, int y, int ex, int ey, vector<vector<int>> &vis, vector<vector<int>> &maze){

        if(vis[x][y] == 0){
            vis[x][y] = 1;
        }
        else{
            return false;
        }
        if(x == ex && y == ey){
            return true;
        }
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            while(xo >= 0 && yo >= 0 && xo < maze.size() && yo < maze[0].size() && maze[xo][yo] == 0){
                xo += dx[i];
                yo += dy[i];
            }
            bool flag = solve(xo - dx[i], yo - dy[i], ex, ey, vis, maze);
            if(flag){
                return true;
            }
        }
        return false;
    }
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int m = maze.size(), n = maze[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        return solve(start[0], start[1], destination[0], destination[1], vis, maze);
    }
};

//Method - 2
class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int dir[4] = {0,1,2,3};
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        
        queue<pair<int,pair<int,int>>> q;
        int m = maze.size(), n = maze[0].size();

        for(int i = 0; i < 4; i++){
            int starto = start[0] + dx[i], endo = start[1] + dy[i];
            if(starto >= 0 && endo >= 0 && starto < m && endo < n){
                q.push({dir[i],{start[0],start[1]}});
            }
        }

        int vis[m][n][4];
        memset(vis,0,sizeof(vis));

        while(!q.empty()){

            int d = q.front().first, x = q.front().second.first, y = q.front().second.second;
            q.pop();

            if(x == destination[0] && y == destination[1]){
                int xo = x + dx[d], yo = y + dy[d];
                if(!(xo >= 0 && yo >= 0 && xo < maze.size() && yo < maze[0].size()) || maze[xo][yo] == 1){
                    return true;
                }
            }
            
            if(vis[x][y][d]) continue;
            vis[x][y][d] = 1;
            
            int xo = x + dx[d], yo = y + dy[d];

            if(xo >= 0 && yo >= 0 && xo < maze.size() && yo < maze[0].size()){
                if(maze[xo][yo] == 0){
                    if(vis[xo][yo][d] == 0){
                        q.push({d,{xo, yo}});
                    }
                }
                else{
                    for(int i = 0; i < 4; i++){
                        if(dir[i] == d) continue;
                        int xoo = x + dx[i], yoo = y + dy[i];
                        if(xoo >= 0 && yoo >= 0 && xoo < m && yoo < n && maze[xoo][yoo] == 0){
                            if(vis[xoo][yoo][dir[i]] == 0){
                                q.push({dir[i],{xoo, yoo}});
                            }
                        }
                    }
                }
            }
            else{
                for(int i = 0; i < 4; i++){
                    if(dir[i] == d) continue;
                    int xoo = x + dx[i], yoo = y + dy[i];
                    if(xoo >= 0 && yoo >= 0 && xoo < m && yoo < n && maze[xoo][yoo] == 0){
                        if(vis[xoo][yoo][dir[i]] == 0){
                            q.push({dir[i],{xoo, yoo}});
                        }
                    }
                }
            }
        }
        return false;
    }
};

//Method - 3
class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int dir[4] = {0,1,2,3};
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        
        queue<pair<int,pair<int,int>>> q;
        int m = maze.size(), n = maze[0].size();

        for(int i = 0; i < 4; i++){
            int starto = start[0] + dx[i], endo = start[1] + dy[i];
            if(starto >= 0 && endo >= 0 && starto < m && endo < n){
                q.push({dir[i],{start[0],start[1]}});
            }
        }

        int vis[m][n][4];
        memset(vis,0,sizeof(vis));

        while(!q.empty()){

            int d = q.front().first, x = q.front().second.first, y = q.front().second.second;
            q.pop();

            if(x == destination[0] && y == destination[1]){
                int xo = x + dx[d], yo = y + dy[d];
                if(!(xo >= 0 && yo >= 0 && xo < maze.size() && yo < maze[0].size()) || maze[xo][yo] == 1){
                    return true;
                }
            }
            
            if(vis[x][y][d]) continue;
            vis[x][y][d] = 1;
            
            int xo = x + dx[d], yo = y + dy[d];

            if(xo >= 0 && yo >= 0 && xo < maze.size() && yo < maze[0].size()){
                if(maze[xo][yo] == 0){
                    if(vis[xo][yo][d] == 0){
                        q.push({d,{xo, yo}});
                        continue;
                    }
                }
            }
            for(int i = 0; i < 4; i++){
                if(dir[i] == d) continue;
                int xoo = x + dx[i], yoo = y + dy[i];
                if(xoo >= 0 && yoo >= 0 && xoo < m && yoo < n && maze[xoo][yoo] == 0){
                    if(vis[xoo][yoo][dir[i]] == 0){
                        q.push({dir[i],{xoo, yoo}});
                    }
                }
            }
        }
        return false;
    }
};
