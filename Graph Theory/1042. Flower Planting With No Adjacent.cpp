class Solution {
public:
    bool solve(int node, vector<int> &col, vector<int> al[]){
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(col[child] == 0){
                for(int j = 1; j <= 4; j++){
                    if(col[node] != j){
                        col[child] = j;
                        bool flag = solve(child, col, al);
                        if(flag){
                            break;
                        }
                    }
                }
            }
            else if(col[child] == col[node]){
                return false;
            }
        }
        return true;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int> col(n + 1, 0);
        
        vector<int> al[n + 1];
        
        for(int i = 0; i < paths.size(); i++){
            int a = paths[i][0], b = paths[i][1];
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        for(int i = 1; i <= n; i++){
            if(col[i] == 0){
                col[i] = 1;
                solve(i, col, al);
            }
        }
        col.erase(col.begin());
        return col;
    }
};
