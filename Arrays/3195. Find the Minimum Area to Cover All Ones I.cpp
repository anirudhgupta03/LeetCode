class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int minRow = INT_MAX, maxRow = INT_MIN, minCol = INT_MAX, maxCol = INT_MIN;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return (maxRow - minRow + 1)*(maxCol - minCol + 1);
    }
};
