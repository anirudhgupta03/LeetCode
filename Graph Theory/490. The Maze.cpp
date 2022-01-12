//https://www.lintcode.com/problem/787/
//Ref: https://www.youtube.com/watch?v=mjDfgdGp-II
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
