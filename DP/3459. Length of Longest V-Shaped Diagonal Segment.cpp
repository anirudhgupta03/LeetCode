class Solution {
public:
    int dx[4] = {-1,1,-1,1};
    int dy[4] = {-1,1,1,-1};
    int dir[4] = {0, 1, 2, 3};
    int n, m, res;
    
    int dp[500][500][4][2];

    int solve(int i, int j, int preEle, int preDir, int flag, vector<vector<int>> &grid){

        int ans = 0;

        if(dp[i][j][preDir][flag] != -1){
            return dp[i][j][preDir][flag];
        }
        
        int ti = i + dx[preDir];
        int tj = j + dy[preDir];
        
        if(ti >= 0 && tj >= 0 && ti < n && tj < m){
            int currEle = grid[ti][tj];
            if(preEle == 1 && currEle == 2 || preEle == 2 && currEle == 0 || preEle == 0 && currEle == 2){
                ans = max(ans, solve(ti, tj, currEle, preDir, flag, grid) + 1);
            }
        }

        int currDir = -1;

        if(preDir == 1){
            currDir = 3;
        }
        else if(preDir == 3){
            currDir = 0;
        }
        else if(preDir == 0){
            currDir = 2;
        }
        else if(preDir == 2){
            currDir = 1;
        }

        ti = i + dx[currDir];
        tj = j + dy[currDir];

        if(ti >= 0 && tj >= 0 && ti < n && tj < m){
            int currEle = grid[ti][tj];
            if(flag == 0 && (preEle == 2 && currEle == 0 || preEle == 0 && currEle == 2)){
                ans = max(ans, solve(ti, tj, currEle, currDir, 1, grid) + 1);
            }
        }

        return dp[i][j][preDir][flag] = ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        res = 0;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int flag = 0;
                        res = max(res, 1 + solve(i, j, 1, k, flag, grid));
                    }
                }
            }
        }

        return res;
    }
};
