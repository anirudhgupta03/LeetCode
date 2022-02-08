//Ref: https://leetcode.com/problems/shortest-path-to-get-all-keys/discuss/146941/C%2B%2B-BFS-with-current-key-recorded-visited-map-(12ms)
class Solution {
public:
    #define vi vector<int>
    #define ppiiv pair<pair<int,int>,vi>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int shortestPathAllKeys(vector<string>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        int keycnt = 0;
        vector<int> keys(6, 0);
        
        int sx, sy;
        for(int i  = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(islower(grid[i][j])){
                    keycnt++;
                }
                if(grid[i][j] == '@'){
                    sx = i;
                    sy = j;
                }
            }
        }
        
        queue<ppiiv> q;
        q.push({{sx,sy},keys});
        
        int steps = 0;
        
        set<ppiiv> vis;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                ppiiv p = q.front();
                q.pop();
                
                int x = p.first.first, y = p.first.second;
                vector<int> temp = p.second;
                int count = 0;
                
                for(int i = 0; i < 6; i++){
                    if(temp[i]) count++;
                }
                
                if(count == keycnt){
                    return steps;
                }
                
                if(vis.find({{x,y},temp}) != vis.end()) continue;
                vis.insert({{x,y}, temp});
                
                for(int i = 0; i < 4; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                        if(islower(grid[xo][yo])){
                            int tp = temp[grid[xo][yo] - 'a'];
                            temp[grid[xo][yo] - 'a'] = 1;
                            if(vis.find({{xo,yo}, temp}) == vis.end())
                            q.push({{xo,yo},temp});
                            temp[grid[xo][yo] - 'a'] = tp;
                        }
                        else if(isupper(grid[xo][yo])){
                            if(temp[grid[xo][yo] - 'A']){
                                if(vis.find({{xo,yo}, temp}) == vis.end())
                                q.push({{xo, yo},temp});
                            }
                        }
                        else if(grid[xo][yo] == '.' || grid[xo][yo] == '@'){
                            if(vis.find({{xo,yo}, temp}) == vis.end())
                            q.push({{xo,yo},temp});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
