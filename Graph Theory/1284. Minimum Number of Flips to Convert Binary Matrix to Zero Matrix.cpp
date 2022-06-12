//Method - 1
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

//Method - 2
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define pivvi pair<int,vector<vector<int>>>
    void findNextStates(queue<pivvi> &q, int &tcount, vector<vector<int>> mat, set<vector<vector<int>>> &vis){
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                mat[i][j] = 1 - mat[i][j];
                if(mat[i][j]) tcount--;
                else    tcount++;
                
                for(int p = 0; p < 4; p++){
                    int io = i + dx[p], jo = j + dy[p];
                    if(io >= 0 && jo >= 0 && io < mat.size() && jo < mat[0].size()){
                        mat[io][jo] = 1 - mat[io][jo];
                        if(mat[io][jo]) tcount--;
                        else tcount++;
                    }
                }
                if(vis.find(mat) == vis.end()){
                    q.push({tcount, mat});
                }
                mat[i][j] = 1 - mat[i][j];
                if(mat[i][j]) tcount--;
                else tcount++;
                
                for(int p = 0; p < 4; p++){
                    int io = i + dx[p], jo = j + dy[p];
                    if(io >= 0 && jo >= 0 && io < mat.size() && jo < mat[0].size()){
                        mat[io][jo] = 1 - mat[io][jo];
                        if(mat[io][jo]) tcount--;
                        else tcount++;
                    }
                }
            }
        }
    }
    int minFlips(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) count++;
            }
        }
        if(count == m*n){
            return 0;
        }
        
        queue<pivvi> q;
        
        q.push({count,mat});
        
        int steps = 0;
        
        set<vector<vector<int>>> vis;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int tcount = q.front().first;
                mat = q.front().second;
                q.pop();
                
                if(vis.find(mat) != vis.end()) continue;
                vis.insert(mat);
                
                if(tcount == m*n){
                    return steps;
                }
                
                findNextStates(q, tcount, mat, vis);
            }
            steps++;
        }
        return -1;
    }
};
