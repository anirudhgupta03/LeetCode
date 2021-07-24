class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size(), ind = 0;
        
        vector<int> dp(n*n);
        
        bool flag = true;
        for(int i = n - 1; i >= 0; i--){
            
            if(flag){
                for(int j = 0; j < n; j++){
                    if(board[i][j] == -1){
                        dp[ind] = ind;
                    }
                    else{
                        dp[ind] = board[i][j] - 1;
                    }
                    ind++;
                }
            }
            else{
                for(int j = n - 1; j >= 0; j--){
                    if(board[i][j] == -1){
                        dp[ind] = ind;
                    }
                    else{
                        dp[ind] = board[i][j] - 1;
                    }
                    ind++;
                }
            }
            flag  = !flag;
        }
        
        vector<int> dist(n*n,-1), vis(n*n,0);
        
        dist[0] = 0;
        vis[0] = 1;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            for(int j = curr + 1; j <= curr + 6 && j < n*n; j++){
                if(vis[dp[j]] == 0){
                    vis[dp[j]] = 1;
                    dist[dp[j]] = dist[curr] + 1;
                    q.push(dp[j]);
                }
            }
        }
        
        return dist[n*n-1];
    }
};
