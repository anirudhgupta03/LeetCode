//Method - 1
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

//Method - 2(Might be correct not sure question can't be accessed now)
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
int dir[4] = {0,1,2,3};
string dc[4] = {"d","l","r","u"};
string findShortestWay(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    
    queue<pair<pair<string,int>,pair<int,int>>> q;
    int m = maze.size(), n = maze[0].size();

    for(int i = 0; i < 4; i++){
        int starto = start[0] + dx[i], endo = start[1] + dy[i];
        if(starto >= 0 && endo >= 0 && starto < m && endo < n){
            q.push({{dc[i],dir[i]},{start[0],start[1]}});
        }
    }

    int vis[m][n][4];
    memset(vis,0,sizeof(vis));
    int steps = 0;

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            string path = q.front().first.first;
            int d = q.front().first.second, x = q.front().second.first, y = q.front().second.second;
            q.pop();

            if(x == destination[0] && y == destination[1]){
                return path;
            }
            
            if(vis[x][y][d]) continue;
            vis[x][y][d] = 1;
            
            int xo = x + dx[d], yo = y + dy[d];

            if(xo >= 0 && yo >= 0 && xo < maze.size() && yo < maze[0].size()){
                if(maze[xo][yo] == 0 && vis[xo][yo][d] == 0){
                        q.push({{path,d},{xo, yo}});
                        continue;
                }
            }
            for(int i = 0; i < 4; i++){
                if(dir[i] == d) continue;
                int xoo = x + dx[i], yoo = y + dy[i];
                if(xoo >= 0 && yoo >= 0 && xoo < m && yoo < n && maze[xoo][yoo] == 0){
                    if(vis[xoo][yoo][dir[i]] == 0){
                        q.push({{path + dc[i],dir[i]},{xoo, yoo}});
                    }
                }
            }
        }
        steps++;
    }
    return "impossible";
}

int main(){
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> maze(m, vector<int>(n));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }
 
    vector<int> start(2), destination(2);
    
    cin >> start[0] >> start[1];
    cin >> destination[0] >> destination[1];
    
    cout << findShortestWay(maze, start, destination) << endl;
}
