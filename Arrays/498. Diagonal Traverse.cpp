class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int dir = 0, i = 0, j = 0;
        vector<int> res;

        while(res.size() != m*n){
            if(dir == 0){
                while(i >= 0 && j < n){
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                if(j >= n){
                    i = i + 2;
                    j = n - 1;
                }
                else if(i < 0){
                    i = 0;
                }
            }
            else{
                while(i < m && j >= 0){
                    res.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                if(i >= m){
                    j = j + 2;
                    i = m - 1;
                }
                else if(j < 0){
                    j = 0;
                }
            }
            dir = !dir;
        }
        return res;
    }
};
