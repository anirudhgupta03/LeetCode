class Solution {
public:
    bool isValid(int row, int col, char num, vector<vector<char>> &board){
        //row
        for(int j = 0; j < board[0].size(); j++){
            if(board[row][j] == num){
                return false;
            }
        }
        //col
        for(int i = 0; i < board.size(); i++){
            if(board[i][col] == num){
                return false;
            }
        }
        int rowi = (row/3)*3;
        int colj = (col/3)*3;
        for(int i = rowi; i < rowi + 3; i++){
            for(int j = colj; j < colj + 3; j++){
                if(board[i][j] == num){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(int i, int j, int m, int n, vector<vector<char>> &board, vector<vector<char>> &ans){
        if(i == m){
            ans = board;
            return true;
        }
        if(j == n){
            return solve(i + 1, 0, m, n, board, ans);
        }
        else{
            if(board[i][j] == '.'){
                for(char num = '1'; num <= '9'; num++){
                    if(isValid(i, j, num, board)){
                        board[i][j] = num;
                        bool flag = solve(i, j + 1, m, n, board, ans);
                        if(flag == true) return true;
                        board[i][j] = '.';
                    }
                }
            }
            else{
                return solve(i, j + 1, m, n, board, ans);
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int m = 9, n = 9;
        vector<vector<char>> ans;
        solve(0, 0, m, n, board, ans);
        board = ans;
    }
};
