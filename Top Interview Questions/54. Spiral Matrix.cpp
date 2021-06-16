class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int t = 0, l = 0, b = m - 1, r = n - 1;
        
        int dir = 1, i = 0, j = 0;
        
        vector<int> res;
        
        int count = 0;
        
        while(count != m*n){
            
            if(dir == 1){
                while(j <= r){
                    res.push_back(matrix[i][j]);
                    count++;
                    j++;
                }
                t++;
                j--;
                i++;
                while(i <= b){
                    count++;
                    res.push_back(matrix[i][j]);
                    i++;
                }
                i--;
                j--;
                r--;
                dir = -1;
            }
            else{
                
                while(j >= l){
                    res.push_back(matrix[i][j]);
                    count++;
                    j--;
                }
                j++;
                i--;
                b--;
                while(i >= t){
                    res.push_back(matrix[i][j]);
                    count++;
                    i--;
                }
                i++;
                j++;
                l++;
                dir = 1;
            }
        }
        return res;
    }
};
