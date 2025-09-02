//Ref: https://www.youtube.com/watch?v=3Zv-s9UUrFM&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=16
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        int mini = 0, maxi = m - 1, minj = 0, maxj = n - 1, dir = 0;

        vector<int> res;

        while(res.size() != m*n){
            if(dir == 0){
                for(int j = minj; j <= maxj; j++){
                    res.push_back(matrix[mini][j]);
                }
                dir = 1;
                mini++;
            }
            else if(dir == 1){
                for(int i = mini; i <= maxi; i++){
                    res.push_back(matrix[i][maxj]);
                }
                dir = 2;
                maxj--;
            }
            else if(dir == 2){
                for(int j = maxj; j >= minj; j--){
                    res.push_back(matrix[maxi][j]);
                }
                dir = 3;
                maxi--;
            }
            else if(dir == 3){
                for(int i = maxi; i >= mini; i--){
                    res.push_back(matrix[i][minj]);
                }
                dir = 0;
                minj++;
            }
        }

        return res;
    }
};
