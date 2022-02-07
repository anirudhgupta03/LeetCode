class Solution {
public:
    #define vvi vector<vector<int>>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int minFlips(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> target(m, vector<int>(n, 0));
        
        queue<vvi> q;
        q.push(mat);
        
        int steps = 0;
        set<vvi> vis;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vvi curr = q.front();
                q.pop();
                
                if(curr == target){
                    return steps;
                }
                
                if(vis.find(curr) != vis.end()) continue;
                vis.insert(curr);
                
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < n; j++){
                        int temp = curr[i][j];
                        curr[i][j] = 1 - temp;
                        for(int k = 0; k < 4; k++){
                            int io = i + dx[k], jo = j + dy[k];
                            if(io >= 0 && jo >= 0 && io < m && jo < n){
                                curr[io][jo] = 1 - curr[io][jo]; 
                            }
                        }
                        if(vis.find(curr) == vis.end()){
                            q.push(curr);
                        }
                        for(int k = 0; k < 4; k++){
                            int io = i + dx[k], jo = j + dy[k];
                            if(io >= 0 && jo >= 0 && io < m && jo < n){
                                curr[io][jo] = 1 - curr[io][jo]; 
                            }
                        }
                        curr[i][j] = temp;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
