class Solution {
public:
    #define pii pair<int,int>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &heights, int sea, vector<vector<pii>> &v){
        
        vis[x][y] = 1;
        if(sea == 1) v[x][y].first = 1;
        else         v[x][y].second = 2;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < v.size() && yo < v[0].size()){
                if(vis[xo][yo] == 0 && heights[xo][yo] >= heights[x][y]){
                    dfs(xo, yo, vis, heights, sea, v);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<pii>> v(m, vector<pii>(n,{-1,-1}));
        
        vector<vector<int>> vis1(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            if(!vis1[i][0]){
                dfs(i, 0, vis1, heights, 1, v);
            }
        }
        
        for(int j = 0; j < n; j++){
            if(!vis1[0][j]){
                dfs(0, j, vis1, heights, 1, v);
            }
        }
        
        vector<vector<int>> vis2(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            if(!vis2[i][n - 1]){
                dfs(i, n - 1, vis2, heights, 2, v);
            }
        }
        
        for(int j = 0; j < n; j++){
            if(!vis2[m - 1][j]){
                dfs(m - 1, j, vis2, heights, 2, v);
            }
        }
        
        vector<vector<int>> res;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j].first == 1 && v[i][j].second == 2){
                    vector<int> temp = {i,j};
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
