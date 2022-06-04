//Method - 1
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int rows = triangle.size();
        
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(j == 0){
                    triangle[i][j] += triangle[i-1][j];
                }
                else if(j == triangle[i].size() - 1){
                    triangle[i][j] += triangle[i-1][j-1];
                }
                else{
                    triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
        }
        int minSum = INT_MAX;
        for(int j = 0; j < triangle[rows - 1].size(); j++){
            minSum = min(minSum, triangle[rows - 1][j]);
        }
        return minSum;
    }
};

//Method - 2
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        vector<int> v(n);
        
        for(int j = 0; j < n; j++){
            v[j] = triangle[n - 1][j];
        }
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                v[j] = min(v[j], v[j + 1]) + triangle[i][j];
            }
        }
        
        return v[0];
    }
};
