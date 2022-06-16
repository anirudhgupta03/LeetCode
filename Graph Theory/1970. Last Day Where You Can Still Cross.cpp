//Binary Search + DFS
//Ref: https://leetcode.com/problems/last-day-where-you-can-still-cross/discuss/1404042/C%2B%2B-Binary-Search-and-DFS
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid){
        
        if(x == grid.size() - 1){
            return true;
        }
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size() && grid[xo][yo] == 0 && vis[xo][yo] == 0){
                bool flag = dfs(xo, yo, vis, grid);  
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
    bool isPossible(int mid, vector<vector<int>> &grid, int m, int n){
    
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int j = 0; j < n; j++){
            if(vis[0][j] == 0 && grid[0][j] == 0){
                bool flag = dfs(0, j, vis, grid);
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        map<int,vector<vector<int>>> mp;
        
        int days = cells.size();
        
        int lo = 0, hi = days;
        int ans;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            vector<vector<int>> grid(row, vector<int>(col, 0));
            
            for(int i = 0; i < mid; i++){
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            
            if(isPossible(mid, grid, row, col)){
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
    
};

//Binary Search + BFS
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isPossibleToCross(int day, vector<vector<int>> &cells, int row, int col){
        
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        for(int i = 0; i <= day; i++){
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        
        queue<pair<int,int>> q;
        
        for(int j = 0; j < col; j++){
            if(grid[0][j] == 0){
                q.push({0, j});
            }
        }
        
        while(!q.empty()){
            
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            if(x == row - 1){
                return true;
            }
            if(grid[x][y]) continue;
            grid[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < row && yo < col && grid[xo][yo] == 0){
                    q.push({xo, yo});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int lo = 0, hi = cells.size() - 1, ans;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(isPossibleToCross(mid, cells, row, col)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans + 1;
    }
};
