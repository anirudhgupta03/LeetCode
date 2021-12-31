class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> lr(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            if(mat[i][0] == 0) lr[i][0] = 0;
            else if(mat[i][0] == 1) lr[i][0] = INT_MAX;
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                if(mat[i][j] == 0){
                    lr[i][j] = 0;
                }
                else{
                    if(lr[i][j-1] == INT_MAX){
                        lr[i][j] = INT_MAX;
                    }
                    else{
                        lr[i][j] = lr[i][j-1] + 1;
                    }
                }
            }
        }
        
        vector<vector<int>> rl(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            if(mat[i][n - 1] == 0) rl[i][n - 1] = 0;
            else rl[i][n - 1] = INT_MAX;
        }
        
        for(int i = 0; i < m; i++){
            for(int j = n - 2; j >= 0; j--){
                if(mat[i][j] == 0){
                    rl[i][j] = 0;
                }
                else{
                    if(rl[i][j+1] == INT_MAX){
                        rl[i][j] = INT_MAX;
                    }
                    else{
                        rl[i][j] = rl[i][j+1] + 1;
                    }
                }
            }
        }
        
        //Top to bottom
        for(int j = 0; j < n; j++){
            for(int i = 1; i < m; i++){
                if(lr[i-1][j] != INT_MAX) lr[i][j] = min(lr[i][j], lr[i-1][j] + 1);
            }
        }
        
        //Bottom to top
        for(int j = 0; j < n; j++){
            for(int i = m - 2; i >= 0; i--){
                if(lr[i+1][j] != INT_MAX) lr[i][j] = min(lr[i][j], lr[i+1][j] + 1);
            }
        }
        
        //Top to bottom
        for(int j = 0; j < n; j++){
            for(int i = 1; i < m; i++){
                if(rl[i-1][j] != INT_MAX) rl[i][j] = min(rl[i][j], rl[i-1][j] + 1);
            }
        }
        
        //Bottom to top
        for(int j = 0; j < n; j++){
            for(int i = m - 2; i >= 0; i--){
                if(rl[i+1][j] != INT_MAX) rl[i][j] = min(rl[i][j], rl[i+1][j] + 1);
            }
        }
        
        vector<vector<int>> res(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res[i][j] = min(lr[i][j], rl[i][j]);
            }
        }
        return res;
    }
};
