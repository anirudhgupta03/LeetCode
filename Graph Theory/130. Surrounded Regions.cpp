class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void change(int x, int y, vector<vector<char>> &board){
        
        board[x][y] = '*';
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && xo < board.size() && yo >= 0 && yo < board[0].size() && board[xo][yo] == 'O'){
                change(xo,yo,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    if(board[i][j] == 'O'){
                        change(i,j,board);
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
