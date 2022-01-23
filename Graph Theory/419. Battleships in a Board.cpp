class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int k, int x, int y, vector<vector<int>> &vis, vector<vector<char>> &board, int &temp){
        
        temp++;
        vis[x][y] = 1;
        
        int xo = x + dx[k], yo = y + dy[k];
        
        if(xo >= 0 && yo >= 0 && xo < board.size() && yo < board[0].size() && board[xo][yo] == 'X' && vis[xo][yo] == 0){
            dfs(k, xo, yo, vis, board, temp);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        
        int m = board.size(), n = board[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X' && vis[i][j] == 0){
                    bool flag = false;
                    for(int k = 0; k < 4; k++){
                        int temp = 0;
                        dfs(k, i, j, vis, board, temp);
                        if(!flag && temp >= 2){
                            flag = true;
                            count++;
                        }
                        else{
                            if(temp > 1){
                                count++;
                            }
                        }
                    }
                    if(!flag){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
