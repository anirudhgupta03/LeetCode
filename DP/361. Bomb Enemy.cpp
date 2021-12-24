class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    void print(vector<vector<int>> v){
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int dc[4] = {3,4,1,2};
    int maxKilledEnemies(vector<vector<char>> &grid) {
         
         int m = grid.size();

        if(m == 0){
            return 0;
        }
        int n = grid[0].size();
         vector<vector<int>> lr(m, vector<int>(n,0));
         vector<vector<int>> rl(m, vector<int>(n,0));
         vector<vector<int>> tb(m, vector<int>(n,0));
         vector<vector<int>> bt(m, vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'E'){
                    if(j == 0) lr[i][j] = 1;
                    else       lr[i][j] = 1 + lr[i][j-1];
                }
                else if(grid[i][j] == 'W'){
                    lr[i][j] = 0;
                }  
                else if(grid[i][j] == '0'){
                    if(j == 0) lr[i][j] = 0;
                    else       lr[i][j] = lr[i][j-1];
                }
            }
        }
        print(lr);

        for(int i = 0; i < m; i++){
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 'E'){
                    if(j == n - 1) rl[i][j] = 1;
                    else       rl[i][j] = rl[i][j+1] + 1;
                }
                else if(grid[i][j] == 'W'){
                    rl[i][j] = 0;
                }  
                else if(grid[i][j] == '0'){
                    if(j == n - 1) rl[i][j] = 0;
                    else       rl[i][j] = rl[i][j+1];
                }
            }
        }

        print(rl);

        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(grid[i][j] == 'E'){
                    if(i == 0) tb[i][j] = 1;
                    else       tb[i][j] = tb[i-1][j] + 1;
                }
                else if(grid[i][j] == 'W'){
                    tb[i][j] = 0;
                }  
                else if(grid[i][j] == '0'){
                    if(i == 0) tb[i][j] = 0;
                    else       tb[i][j] = tb[i-1][j];
                }
            }
        }

        print(tb);

        for(int j = 0; j < n; j++){
            for(int i = m - 1; i >= 0; i--){
                if(grid[i][j] == 'E'){
                    if(i == m - 1) bt[i][j] = 1;
                    else       bt[i][j] = bt[i+1][j] + 1;
                }
                else if(grid[i][j] == 'W'){
                    bt[i][j] = 0;
                }  
                else if(grid[i][j] == '0'){
                    if(i == m - 1) bt[i][j] = 0;
                    else       bt[i][j] = bt[i+1][j];
                }
            }
        }

        print(bt);
        int maxsum = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j] == '0'){
                    int sum = 0;
                    for(int k = 0; k < 4; k++){
                        int io = i + dx[k], jo = j + dy[k];
                        if(io >= 0 && jo >= 0 && jo < n && io < m){
                            int v = dc[k];
                            if(v == 1) sum += lr[io][jo];
                            if(v == 2) sum += rl[io][jo];
                            if(v == 3) sum += tb[io][jo];
                            if(v == 4) sum += bt[io][jo]; 
                        }
                    } 
                    maxsum = max(maxsum, sum);   
                }
            }   
        }
        return maxsum;
    }
};
