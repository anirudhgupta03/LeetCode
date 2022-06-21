//https://www.lintcode.com/problem/860/
//Ref: https://www.youtube.com/watch?v=4vY_ZPi9jTs
//Optimal Approach
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char dc[4] = {'U','D','L','R'};

    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, string &path){
        
        vis[x][y] = 1;

        for(int i = 0; i < 4; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && xo < grid.size() && yo >= 0 && yo < grid[0].size()){
                if(vis[xo][yo] == 0 && grid[xo][yo] == 1){
                    path.push_back(dc[i]);
                    dfs(xo, yo, grid, vis,path);
                    path.push_back('B');                                          //Indicate Backtracking
                }
            }
        }
    }
    void print(vector<vector<int>> v){

        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        
        int m = grid.size(), n = grid[0].size();

        map<string,int> mp;

        int count = 0;

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1 && vis[i][j] == 0){

                    string path = "S";

                    dfs(i,j,grid,vis,path);
                    
                    if(mp.find(path) == mp.end()){
                        count++;
                        mp[path] = 1;
                    }
                }
            }
        }
        return count;
    }
};

//Brute Force Approach
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<vector<int>> &tvis){
        
        vis[x][y] = 1;
        tvis[x][y] = 1;

        for(int i = 0; i < 4; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && xo < grid.size() && yo >= 0 && yo < grid[0].size()){
                if(vis[xo][yo] == 0 && grid[xo][yo] == 1){
                    dfs(xo, yo, grid, vis,tvis);
                }
            }
        }
    }
    void print(vector<vector<int>> v){

        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        
        int m = grid.size(), n = grid[0].size();

        map<vector<vector<int>>,int> mp;

        int count = 0;

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){

                    vector<vector<int>> tvis(m,vector<int>(n,0));
                    dfs(i,j,grid,vis,tvis);

                    int width = 0, height = 0;

                    int xstart = -1, xend = -1, ystart = INT_MAX, yend = -1;

                    int minystart = INT_MAX, maxyend = 0;

                    //print(tvis);

                    bool flag1 = false;
                    for(int k = 0; k < m; k++){
                        bool flag2 = false;
                        for(int l = 0; l < n; l++){
                            if(tvis[k][l] == 1){
                                 if(!flag2){
                                     flag2 = true;
                                     ystart = l;
                                     yend = l;
                                 }
                                 else{
                                     yend = l;
                                 }

                                 if(!flag1){
                                     flag1 = true;
                                     xstart = k;
                                     xend = k;
                                 }
                                 else{
                                     xend = k;
                                 }
                            }
                        }
                        if(flag2){
                            minystart = min(minystart, ystart);
                            maxyend = max(maxyend, yend);
                            width = max(width, yend - ystart + 1);
                        }
                        if(flag1){
                            height = max(height, xend - xstart + 1);
                        }
                    }

                    vector<vector<int>> temp(height,vector<int>(maxyend - minystart + 1,0));

                    cout << xstart << " " << xend << endl;
                    cout << minystart << " " << maxyend << endl;

                    for(int i = xstart; i <= xend; i++){
                        for(int j = minystart; j <= maxyend; j++){
                            temp[i-xstart][j-minystart] = tvis[i][j];
                        }
                    }
                    
                    print(temp);
                    if(mp.find(temp) == mp.end()){
                        count++;
                        mp[temp] = 1;
                    }
                }
            }
        }
        return count;
    }
};

//Another Approach - https://www.geeksforgeeks.org/find-the-number-of-distinct-islands-in-a-2d-matrix/
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, int basex, int basey, vector<pair<int,int>> &path, vector<vector<int>> &grid){

        path.push_back({x - basex, y - basey});
        grid[x][y] = 0;

        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size() && grid[xo][yo]){
                dfs(xo, yo, basex, basey, path, grid);
            }
        }
    }
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        
        set<vector<pair<int,int>>> islands;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    vector<pair<int,int>> path;
                    dfs(i, j, i, j, path, grid);
                    islands.insert(path);
                }
            }
        }
        return islands.size();
    }
};
