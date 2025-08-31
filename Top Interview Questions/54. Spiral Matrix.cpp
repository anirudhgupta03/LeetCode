class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0, mini = 0, maxi = m - 1, minj = 0, maxj = n - 1, dir = 0;
        vector<int> res;
        while(res.size() != m*n){
            if(dir == 0){
                while(j <= maxj){
                    res.push_back(matrix[i][j]);
                    j++;
                }
                dir = 1;
                j = maxj;
                i = mini + 1;
                mini++;
            }
            else if(dir == 1){
                while(i <= maxi){
                    res.push_back(matrix[i][j]);
                    i++;
                }
                dir = 2;
                i = maxi;
                j = maxj - 1;
                maxj--;
            }
            else if(dir == 2){
                while(j >= minj){
                    res.push_back(matrix[i][j]);
                    j--;
                }
                dir = 3;
                j = minj;
                i = maxi - 1;
                maxi--;
            }
            else if(dir == 3){
                while(i >= mini){
                    res.push_back(matrix[i][j]);
                    i--;
                }
                dir = 0;
                i = mini;
                j = minj + 1;
                minj++;
            }
        }

        return res;
    }
};
