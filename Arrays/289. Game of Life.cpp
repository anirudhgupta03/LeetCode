//Time Complexity - O(8*m*n)
//Space Complexity - O(m*n)
class Solution {
public:
    int dx[8] = {0,0,-1,1,1,1,-1,-1};
    int dy[8] = {1,-1,0,0,1,-1,1,-1};
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> temp = board;
        
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(temp[i][j] == 1){
                    int count = 0;
                    for(int k = 0; k < 8; k++){
                        int io = i + dx[k], jo = j + dy[k];
                        if(io >= 0 && io < m && jo >= 0 && jo < n){
                            if(board[io][jo] == 1){
                                count++;
                            }
                        }
                    }
                    
                    if(count < 2){
                        temp[i][j] = 0;
                    }
                    else if(count == 2 || count == 3){
                        temp[i][j] = 1;
                    }
                    else if(count > 3){
                        temp[i][j] = 0;
                    }
                }
                else{
                    int count = 0;
                    for(int k = 0; k < 8; k++){
                        int io = i + dx[k], jo = j + dy[k];
                        if(io >= 0 && io < m && jo >= 0 && jo < n){
                            if(board[io][jo] == 1){
                                count++;
                            }
                        }
                    }
                    if(count == 3){
                        temp[i][j] = 1;
                    }
                }
            }
        }
        board = temp;
    }
};

//Time Complexity - O(8*m*n)
//Space Complexity - O(1)
class Solution {
public:
    int dx[8] = {0,0,-1,1,1,1,-1,-1};
    int dy[8] = {1,-1,0,0,1,-1,1,-1};
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                    int count = 0;
                    for(int k = 0; k < 8; k++){
                        int io = i + dx[k], jo = j + dy[k];
                        if(io >= 0 && io < m && jo >= 0 && jo < n){
                            if(abs(board[io][jo]) == 1){
                                count++;
                            }
                        }
                    }
                    if(board[i][j] == 1){
                        if(count < 2 || count > 3){
                            board[i][j] = -1;
                        }
                    }
                    else{
                        if(count == 3){
                            board[i][j] = 2;
                        }
                    }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = board[i][j] > 0 ? 1 : 0;
            }
        }
    }
};
