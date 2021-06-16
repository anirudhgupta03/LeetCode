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
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
