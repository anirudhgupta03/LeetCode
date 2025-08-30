//Method - 1
class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    int solve(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int maxlen = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && xo < matrix.size() && yo >= 0 && yo < matrix[0].size() && matrix[xo][yo] > matrix[x][y]){
                maxlen = max(maxlen, solve(xo,yo,matrix,dp) + 1);
            }
        }
        
        return dp[x][y] = maxlen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int lip = 1;
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                lip = max(lip,solve(i,j,matrix,dp));
            }
        }
        return lip;
    }
};

//Method - 2
//Using Topological Sorting
//Ref: https://www.youtube.com/watch?v=aN5EZa6cypU
#define pii pair<int,int>
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> indegree(m, vector<int>(n,0));
        vector<vector<vector<pii>>> al(m, vector<vector<pii>>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int di = -1, dj = -1;
                for(int k = 0; k < 4; k++){
                    di = i + dx[k];
                    dj = j + dy[k];
                    if(di >= 0 && dj >= 0 && di < m && dj < n && matrix[di][dj] > matrix[i][j]){
                        al[i][j].push_back({di, dj});
                        indegree[di][dj]++;
                    }
                }
            }
        }

        queue<pii> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(indegree[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> path;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                pii p = q.front();
                q.pop();
                vector<pii> tp = al[p.first][p.second];
                for(int i = 0; i < tp.size(); i++){
                    indegree[tp[i].first][tp[i].second]--;
                    if(indegree[tp[i].first][tp[i].second] == 0){
                        q.push({tp[i].first, tp[i].second});
                    }
                }
            }
        }
        return ans;
    }
};
