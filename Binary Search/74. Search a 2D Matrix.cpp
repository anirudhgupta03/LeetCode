//Ref: https://www.youtube.com/watch?v=JXU4Akft7yk&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=25
//Method - 1
//TC: O(N) + logM
//SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            if(matrix[i][0] <= target && target <= matrix[i][n - 1]){
                int lo = 0, hi = n - 1;
                while(lo <= hi){
                    int mid = lo + (hi - lo)/2;
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    else if(matrix[i][mid] < target){
                        lo = mid + 1;
                    }
                    else{
                        hi = mid - 1;
                    }
                }
                return false;
            }
        }
        return false;
    }
};

//Method - 2
//TC: O(log(M*N))
//SC: O(1)
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

//Method - 3
//Ref: https://www.youtube.com/watch?v=EmpwQ4C6WJs
//TC: O(logM) + O(logN)
//SC: O(1)
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

//Method - 4
//TC: O(M + N)
//SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = m - 1, y = n - 1;
        while(x >= 0 && x < m && y >= 0 && y < n){
            if(matrix[x][y] == target){
                return true;
            }
            else if(x - 1 >= 0 && matrix[x - 1][y] >= target){
                x -= 1;
            }
            else if(y - 1 >= 0){
                y -= 1;
            }
            else{
                return false;
            }
        }
        return false;
    }
};
