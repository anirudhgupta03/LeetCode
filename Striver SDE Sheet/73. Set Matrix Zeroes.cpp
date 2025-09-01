//Ref: https://www.youtube.com/watch?v=N0MgLvceX7M&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=14
//Method - 1
//Time Complexity - O(M*N)
//Space Complexity - O(M+N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> row(m,0);
        vector<int> col(n,0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//Method - 2
//Time Complexity - O(M*N)
//Space Complexity - O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        bool flag1 = false, flag2 = false;
        
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                flag1 = true;
            }
        }
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                flag2 = true;
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(flag1){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
        if(flag2){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
