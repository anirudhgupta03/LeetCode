class Solution {
public:
    bool isValid(int x, int y, vector<vector<char>> &board){
        
        for(int i = x + 1; i < 9; i++){
            if(board[i][y] == board[x][y]){
                return false;
            }
        }
        
        for(int j = y + 1; j < 9; j++){
            if(board[x][j] == board[x][y]){
                return false;
            }
        }
        
        for(int i = (x/3)*3; i < (x/3)*3 + 3; i++){
            for(int j = (y/3)*3; j < (y/3)*3 + 3; j++){
                if(i != x && j != y && board[i][j] == board[x][y]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if(board[i][j] != '.'){
                    
                    if(!isValid(i,j,board)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
