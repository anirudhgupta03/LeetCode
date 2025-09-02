//Ref: https://www.youtube.com/watch?v=Z0R2u6gd3GU&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=15
//Method - 1
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        int l = 0, r = matrix.size() - 1;

        while(l < r){
            for(int j = 0; j < matrix[0].size(); j++){
                swap(matrix[l][j],matrix[r][j]);
            }
            l++;
            r--;
        }
        //Transpose
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

//Method - 2
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();

        //Transpose
        for(int i = 0; i < m; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reverse each row
        for(int i = 0; i < m; i++){
            int lo = 0, hi = n - 1;
            while(lo < hi){
                swap(matrix[i][lo], matrix[i][hi]);
                lo++;
                hi--;
            }
        }
    }
};
