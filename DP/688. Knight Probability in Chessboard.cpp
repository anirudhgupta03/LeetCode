//Method - 1
//Ref: https://www.youtube.com/watch?v=54nJhM2AZv4
class Solution {
public:
    int dx[8] = {-2,-2,-1,-1,2,2,1,1};
    int dy[8] = {-1,1,-2,2,-1,1,-2,2};
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<double>> curr(n, vector<double>(n,0));
        vector<vector<double>> next(n, vector<double>(n));
        
        curr[row][column] = 1;
        
        for(int m = 1; m <= k; m++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(curr[i][j] != 0){
                        for(int p = 0; p < 8; p++){
                            int io = i + dx[p], jo = j + dy[p];
                            
                            if(io >= 0 && io < n && jo >= 0 && jo < n){
                                next[io][jo] += curr[i][j]/8.0;
                            }
                        }
                    }
                }
            }
            curr = next;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    next[i][j] = 0;
                }
            }
        }
        
        double p = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(curr[i][j] != 0){
                    p += curr[i][j];
                }
            }
        }
        return p;
    }
};

//Method - 2
class Solution {
public:
    int dx[8] = {-2,-1,1,2,2,1,-1,-2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    double solve(int row, int column, int n, int k, vector<vector<vector<double>>> &dp){
        
        if(k == 0){
            return 1.0;
        }
        
        if(dp[row][column][k] != -1.0){
            return dp[row][column][k];
        }
        double prob = 0;
        
        for(int i = 0; i < 8; i++){
            int rowo = row + dx[i], columno = column + dy[i];
            if(rowo >= 0 && columno >= 0 && rowo < n && columno < n){
                prob += (0.125)*(solve(rowo, columno, n, k - 1, dp));
            }
        }
        return dp[row][column][k] = prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        return solve(row, column, n, k, dp);
    }
};
