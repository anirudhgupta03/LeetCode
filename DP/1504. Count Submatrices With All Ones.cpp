//Ref: https://www.youtube.com/watch?v=hrd-MEcZkOI
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = n - 2; j >= 0; j--){
                if(mat[i][j] == 1){
                    mat[i][j] += mat[i][j + 1];
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    int temp = mat[i][j];
                    count += temp;
                    for(int k = i + 1; k < m; k++){
                        temp = min(temp, mat[k][j]);
                        count += temp;
                    }
                }
            }
        }
        return count;
    }
};
