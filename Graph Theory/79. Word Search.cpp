class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool dfs(int ind, int x, int y, vector<vector<char>> &board, vector<vector<int>> &vis, string &word){
        
        if(ind == word.size()){
            return true;
        }
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < board.size() && yo < board[0].size() && board[xo][yo] == word[ind] && vis[xo][yo] == 0){
                vis[xo][yo] = 1;
                bool flag = dfs(ind + 1, xo, yo, board, vis, word);
                if(flag) return true;
                vis[xo][yo] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> vis(m, vector<int>(n, 0));
                    vis[i][j] = 1;
                    bool flag = dfs(1, i, j, board, vis, word);
                    if(flag) return true;
                }
            }
        }
        return false;
    }
};
