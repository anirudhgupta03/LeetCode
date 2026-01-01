class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mat = matrix;
        int count = 0;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(mat[i][j]){
                    if(i == m - 1 || j == n - 1){
                        count++;
                    }
                    else{
                        mat[i][j] += min({mat[i + 1][j], mat[i + 1][j + 1], mat[i][j + 1]});
                        count += mat[i][j];
                    }
                }
            }
        }   
        return count;
    }
};
