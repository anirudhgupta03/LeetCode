/*
Understanding question
[9,8,7]
[6,5,4]
[3,2,1]

The execution path, steps and cuts are:
path   9 > 6 > 3 > 2 > 3 > 6 > 5 > 4 > 5 > 6 > 5 > 4 > 7 > 8 > 9
steps  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14     
cuts   0   0   0   1   1   0   0   1   1   1   0   0   1   1   1
*/

//Method - 1
//TLE
class Solution {
public:
    #define pii pair<int,int>
    #define vvi vector<vector<int>>
    #define pppiv pair<pii, pair<pii,vvi>>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void print(vvi v){
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        
        int m = forest.size(), n = forest[0].size();
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(forest[i][j] > 1){
                    count++;
                }
            }
        }
        
        if(count == 0){
            return 0;
        }
        
        queue<pppiv> q;
        if(forest[0][0] > 1){
            int temp = forest[0][0];
            forest[0][0] = 1;
            q.push({{0,0},{{temp,1}, forest}}); 
            forest[0][0] = temp;
        }
        q.push({{0,0},{{1,0}, forest}}); 
            
        set<pair<pii,pair<int,vvi>>> vis;
        
        int steps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            cout << "Level: " << steps << endl;
            while(sz--){
                pii p = q.front().first;
                vvi curr = q.front().second.second;
                int cnt = q.front().second.first.second;
                int ht = q.front().second.first.first;
                q.pop();
                
                int x = p.first, y = p.second;
                
                if(cnt == count){
                    return steps;
                }
                
                if(vis.find({p,{ht,curr}}) != vis.end()) continue;
                vis.insert({p,{ht,curr}});
                
                // print(curr);
                
                for(int i = 0; i < 4; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                        if(curr[xo][yo] == 1){
                            if(vis.find({{xo,yo},{ht,curr}}) == vis.end()){
                                q.push({{xo,yo},{{ht, cnt},curr}});
                            }
                        }
                        else if(curr[xo][yo] > 1){
                            if(curr[xo][yo] > ht){
                                int temp = curr[xo][yo];
                                curr[xo][yo] = 1;
                                if(vis.find({{xo,yo},{temp, curr}}) == vis.end()){
                                    q.push({{xo,yo},{{temp, cnt  + 1},curr}});
                                }
                                curr[xo][yo] = temp;
                            }
                            if(vis.find({{xo,yo},{ht,curr}}) == vis.end()){
                                q.push({{xo,yo},{{ht, cnt},curr}});
                            }
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

//Method - 2
//Ref: https://leetcode.com/problems/cut-off-trees-for-golf-event/discuss/1518847/C%2B%2B-chunk-by-chunk-with-BFS
class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int solve(vector<vector<int>> &forest, int sx, int sy, int dstx, int dsty, int m, int n){
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push({sx,sy});
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x == dstx && y == dsty){
                    return steps;
                }
                
                if(vis[x][y]) continue;
                vis[x][y] = 1;
                
                for(int i = 0; i < 4; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                        if(vis[xo][yo] == 0 && forest[xo][yo] != 0){
                            q.push({xo,yo});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        
        int m = forest.size(), n = forest[0].size();
        
        vector<pipii> trees;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(forest[i][j] > 1){
                    trees.push_back({forest[i][j],{i,j}});
                }
            }
        }
        
        sort(trees.begin(), trees.end());
        
        int x = 0, y = 0;
        int steps = 0;
        
        for(int i = 0; i < trees.size(); i++){
            int xo = trees[i].second.first, yo = trees[i].second.second;
            
            int tsteps = solve(forest, x, y, xo, yo, m, n);
            
            if(tsteps == -1){
                return - 1;
            }
            
            steps += tsteps;
            forest[xo][yo] = 1;
            
            x = xo;
            y = yo;
        }
        return steps;
    }
};
