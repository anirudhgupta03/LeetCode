//Ref: https://www.youtube.com/watch?v=qCKXRsIItG8
//Method - 1
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

//Method - 2
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<int> res(n,-1);
        
        for(int i = 0; i < n; i++){

            int x = 0, y = i;
            
            while(x < m && y >= 0 && y < n){
                if(grid[x][y] == 1){
                    if(y + 1 < n && grid[x][y + 1] == -1){
                        break;
                    }
                    else{
                        x++;
                        y++;
                    }
                }
                else{
                    if(y - 1 >= 0 && grid[x][y - 1] == 1){
                        break;
                    }
                    else{
                        x++;
                        y--;
                    }
                }
            }
            if(x == m && y >= 0 && y < n){
                res[i] = y;
            }
        }
        return res;
    }
};
