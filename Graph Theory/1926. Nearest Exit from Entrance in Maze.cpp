class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size(), n = maze[0].size();
        
        int s = entrance[0], e = entrance[1];
        
        queue<pair<pair<int,int>,int>> q;
        
        q.push({{s,e},0});
        
        int minsteps = INT_MAX;
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[s][e] = 1;
        
        while(!q.empty()){
            
            int x = q.front().first.first, y = q.front().first.second, d = q.front().second;
            q.pop();
            
            if(x == m - 1 || x == 0 || y == n - 1 || y == 0){
                
                if(x != s || y != e){
                    minsteps = min(minsteps, d);
                    continue;
                }
                
            }
            
            for(int i = 0; i < 4; i++){
                
                int xo = x + dx[i], yo = y + dy[i];
                
                if(xo >= 0 && xo < m && yo >= 0 && yo < n && vis[xo][yo] == 0 && maze[xo][yo] == '.'){
                    vis[xo][yo] = 1;
                    q.push({{xo,yo},d+1});
                }
            }
        }
              
        if(minsteps == INT_MAX){
            return -1;
        }
        return minsteps;
    }
};
