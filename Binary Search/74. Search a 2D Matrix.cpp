//Method - 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int lo = 0, hi = m*n - 1, x, y;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            x = mid/n, y = mid%n;
            
            if(matrix[x][y] > target){
                hi = mid - 1;
            }
            else if(matrix[x][y] < target){
                lo = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=EmpwQ4C6WJs
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int lo = 0, hi = m - 1, row = -1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1]){
                row = mid;
                break;
            }
            else if(target < matrix[mid][0]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        if(row == -1) return false;
        
        lo = 0, hi = n - 1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(matrix[row][mid] == target) return true;
            
            else if(matrix[row][mid] > target) hi = mid - 1;
            
            else lo = mid + 1;
        }
        return false;
    }
};
