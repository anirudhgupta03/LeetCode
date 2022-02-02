//Multi Source BFS
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size(), n = isWater[0].size();
        
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    res[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for(int k = 0; k < 4; k++){
                int xo = x + dx[k], yo = y + dy[k];
                if(xo >= 0 && yo >= 0 && xo < m && yo < n){
                    if(isWater[xo][yo] == 0 && res[x][y] + 1 < res[xo][yo]){
                        res[xo][yo] = res[x][y] + 1;
                        q.push({xo, yo});
                    }
                }
            }
        }
        return res;
    }
};
