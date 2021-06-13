//Time Complexity - O(N^4) or O(M^4)
//Space Complexity - O(M*N)
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        int maxSize = 1;
        
        vector<vector<int>> rowSum(m,vector<int>(n+1,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rowSum[i][j+1] = grid[i][j] + rowSum[i][j]; 
            }
        }
        
        vector<vector<int>> colSum(m+1,vector<int>(n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                colSum[i+1][j] = grid[i][j] + colSum[i][j]; 
            }
        }
        
        for(int size = 2; size <= min(m,n); size++){
            
            for(int i = 0; i <= m - size; i++){
                
                for(int j = 0; j <= n - size; j++){
                    
                    int r1sum = rowSum[i][j + size] - rowSum[i][j];
                    
                    
                    bool flag = true;
                    
                    for(int k = i + 1; k < i + size; k++){
                        if(rowSum[k][j + size] - rowSum[k][j] != r1sum){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        continue;
                    }
                    
                    int col1sum = colSum[i + size][j] - colSum[i][j];
                    
                    for(int k = j + 1; k < j + size; k++){
                        if(colSum[i+size][k] - colSum[i][k] != col1sum){
                            flag = false;
                            break;
                        }
                    }
                    
                    if(!flag){
                        continue;
                    }
                    
                    int x = i, y = j;
                    
                    int d1sum = 0;
                    
                    while(x < i + size && y < j + size){
                        d1sum += grid[x][y];
                        x++;
                        y++;
                    }
                    
                    int d2sum = 0;
                    
                    x = i, y = j + size - 1;
                    
                    while(x < i + size && y >= j){
                        d2sum += grid[x][y];
                        x++;
                        y--;
                    }
                    
                    if(d1sum != d2sum){
                        flag = false;
                    }
                    
                    if(!flag){
                        continue;
                    }
                    
                    if(r1sum == col1sum && col1sum == d1sum){
                        maxSize = size;
                    }
                    
                }
            }
        }
        return maxSize;
    }
};
