class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<int> row(m, 0), col(n, 0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        int total = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && (row[i] >= 2 || col[j] >= 2)) total++;
            }
        }
        return total;
    }
};
