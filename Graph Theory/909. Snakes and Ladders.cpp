//Method - 1
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

//Method - 2
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        
        vector<int> grid(n*n + 1);
        int ind = 1;
        
        bool flag = true;
        
        for(int i = n - 1; i >= 0; i--){
            if(flag){
                for(int j = 0; j < n; j++){
                    grid[ind] = board[i][j];
                    ind++;
                }
            }
            else{
                for(int j = n - 1; j >= 0; j--){
                    grid[ind] = board[i][j];
                    ind++;
                }
            }
            flag = !flag;
        }
        
        queue<int> q;
        q.push(1);
        
        vector<int> vis(n*n + 1, 0);
        int steps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                
                if(curr == n*n){
                    return steps;
                }
                if(vis[curr]) continue;
                vis[curr] = 1;
                
                for(int j = 1; j <= 6; j++){
                    int ncurr = curr + j;
                    if(ncurr <= n*n){
                        if(grid[ncurr] != -1){
                            q.push(grid[ncurr]);
                        }
                        else{
                            q.push(ncurr);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
