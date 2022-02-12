//Ref: https://www.youtube.com/watch?v=qCKXRsIItG8
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<int> ans(n, -1);
        
        for(int j = 0; j < n; j++){
            int cpos = j, npos = -1;
            for(int i = 0; i < m; i++){
                npos = cpos + grid[i][cpos]; 
                if(npos < 0 || npos >= n || grid[i][cpos] != grid[i][npos]){
                    cpos = -1;
                    break;
                }
                cpos = npos;
            }
            ans[j] = cpos;
        }
        return ans;
    }
};
