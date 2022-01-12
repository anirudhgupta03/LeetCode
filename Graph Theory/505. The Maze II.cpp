//https://www.lintcode.com/problem/788
//Ref: https://www.youtube.com/watch?v=fdixclqnT3s
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
