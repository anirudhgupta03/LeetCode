class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n,vector<int>(n,0));
        
        int i = 0, j = 0;
        
        int num = 1, dir = 1;
        
        while(num <= n*n){
            
            if(dir == 1){
                while(j <=  n - 1 && res[i][j] == 0){
                    res[i][j] = num;
                    j++;
                    num++;
                }
                j--;
                i++;
                
                while(i <= n - 1 && res[i][j] == 0){
                    res[i][j] = num;
                    i++;
                    num++;
                }
                i--;
                j--;
                dir = -1;
            }
            else{
                while(j >= 0 && res[i][j] == 0){
                    res[i][j] = num;
                    num++;
                    j--;
                }
                
                j++;
                i--;
                while(i >= 0 && res[i][j] == 0){
                    res[i][j] = num;
                    i--;
                    num++;
                }
                
                i++;
                j++;
                dir = 1;
            }
        }
        return res;
    }
};
