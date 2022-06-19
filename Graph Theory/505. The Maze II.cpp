//https://www.lintcode.com/problem/788
//Ref: https://www.youtube.com/watch?v=fdixclqnT3s
//Method - 1
class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define ppiii pair<pair<int,int>,int>
    struct cmp{
        bool operator()(ppiii p1, ppiii p2){
            return p1.second > p2.second;
        }
    };

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        
        int m = maze.size(), n = maze[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        priority_queue<ppiii,vector<ppiii>,cmp> pq;

        pq.push({{start[0],start[1]},0});

        while(!pq.empty()){

            ppiii p = pq.top();
            pq.pop();

            int x = p.first.first, y = p.first.second, dist = p.second;

            if(vis[x][y]){
                continue;
            }
            vis[x][y] = 1;

            if(x == destination[0] && y == destination[1]){
                return dist;
            }
            for(int i = 0; i < 4; i++){
                int d = 0;
                int xo = x + dx[i], yo = y + dy[i];
                while(xo >= 0 && yo >= 0 && xo < m && yo < n && maze[xo][yo] == 0){
                    d++;
                    xo += dx[i];
                    yo += dy[i];
                }
                pq.push({{xo - dx[i], yo - dy[i]}, dist + d});
            }
        }
        return -1;
    }
};

//Method - 2
//Using BFS
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
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        
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
        int steps = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int d = q.front().first, x = q.front().second.first, y = q.front().second.second;
                q.pop();

                if(x == destination[0] && y == destination[1]){
                    int xo = x + dx[d], yo = y + dy[d];
                    if(!(xo >= 0 && yo >= 0 && xo < maze.size() && yo < maze[0].size()) || maze[xo][yo] == 1){
                        return steps;
                    }
                }
                
                if(vis[x][y][d]) continue;
                vis[x][y][d] = 1;
                
                int xo = x + dx[d], yo = y + dy[d];

                if(xo >= 0 && yo >= 0 && xo < maze.size() && yo < maze[0].size()){
                    if(maze[xo][yo] == 0 && vis[xo][yo][d] == 0){
                            q.push({d,{xo, yo}});
                            continue;
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
            steps++;
        }
        return -1;
    }
};
