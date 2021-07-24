class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    
    void solve(int x, int y, int newColor, vector<vector<int>> &image, vector<vector<int>> &vis, int tempColor){
        
        image[x][y] = newColor;
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && xo < image.size() && yo >= 0 && yo < image[0].size()){
                if(vis[xo][yo] == 0 && image[xo][yo] == tempColor){
                    solve(xo,yo,newColor,image,vis,tempColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int m = image.size(), n = image[0].size();
        
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        int tempColor = image[sr][sc];
        
        solve(sr,sc,newColor,image, vis, tempColor);
        return image;
    }
};
