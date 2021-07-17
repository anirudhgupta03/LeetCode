class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    void search(int ind, int x, int y, vector<vector<char>> &board, bool &flag, vector<vector<int>> &vis, string &temp, string &word){
        
        if(temp == word){
            flag = true;
            return;
        }
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && xo < board.size() && yo >= 0 && yo < board[0].size() && vis[xo][yo] == 0 && board[xo][yo] == word[ind]){
                temp.push_back(board[xo][yo]);
                vis[xo][yo] = 1;
                search(ind+1,xo,yo,board,flag,vis,temp,word);
                temp.pop_back();
                vis[xo][yo] = 0;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
              
                if(word[0] == board[i][j]){
                    bool flag = false;
                    vector<vector<int>> vis(m,vector<int>(n,0));
                    string temp;
                    temp.push_back(word[0]);
                    vis[i][j] = 1;
                    search(1,i,j,board,flag,vis,temp,word);
                    
                    if(flag){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
