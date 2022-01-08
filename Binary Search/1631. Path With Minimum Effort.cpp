class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isPath(vector<vector<int>>& heights, int x, int y, vector<vector<int>> &vis, int k){
        
        if(x == heights.size() - 1 && y == heights[0].size() - 1){
            return true;
        }
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < heights.size() && yo < heights[0].size()){
                if(vis[xo][yo] == 0 && abs(heights[xo][yo] - heights[x][y]) <= k){
                    vis[xo][yo] = 1;
                    bool flag = isPath(heights, xo, yo, vis, k);
                    //vis[xo][yo] = 0;                                Doubt
                    if(flag) return true;
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size(), n = heights[0].size();
        
        int lo = 0, hi = 1e6, ans;
        vector<vector<int>> vis(m, vector<int>(n,0));
        vis[0][0] = 1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(isPath(heights, 0, 0, vis, mid)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
