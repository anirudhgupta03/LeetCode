class Solution {
public:
    /**
     * @param maze: the maze
     * @param ball: the ball position
     * @param hole: the hole position
     * @return: the lexicographically smallest way
     */
    #define ppiipis pair<pair<int,int>,pair<int,string>> 
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char dir[4] = {'u','d','l','r'};
    struct cmp{
        bool operator()(ppiipis p1, ppiipis p2){
            if(p1.second.first == p2.second.first){
                return p1.second.second > p2.second.second;
            }
            return p1.second.first > p2.second.first;
        }
    };
    
    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole) {
        
        int m = maze.size(), n = maze[0].size();

        vector<vector<int>> vis(m,vector<int>(n, 0));

        priority_queue<ppiipis, vector<ppiipis>, cmp> pq;

        pq.push({{ball[0],ball[1]},{0,""}});

        string res;

        while(!pq.empty()){

            ppiipis p = pq.top();
            pq.pop();

            int x = p.first.first, y = p.first.second;
            int dist = p.second.first;
            string path = p.second.second;

            if(vis[x][y]){
                continue;
            }
            vis[x][y] = 1;

            if(x == hole[0] && y == hole[1]){
                return path;
            }

            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                int d = 0;
                string s = path;
                bool flag = false;
                if(xo >= 0 && yo >= 0 && xo < m && yo < n && maze[xo][yo] == 0){
                    s.push_back(dir[i]);
                }
                while(xo >= 0 && yo >= 0 && xo < m && yo < n && maze[xo][yo] == 0){
                    d++;
                    if(xo == hole[0] && yo == hole[1]){
                        flag = true;
                        pq.push({{xo, yo},{dist + d, s}});
                        break;
                    }
                    xo += dx[i];
                    yo += dy[i];
                }
                if(!flag)
                pq.push({{xo - dx[i], yo - dy[i]},{dist + d, s}});
            }
        }
        return "impossible";
    }
};
