class Solution {
public:
    bool bipartitionPossible(int node, vector<int> &col, vector<int> al[]){
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(col[child] != -1){
                if(col[child] == col[node]){
                    return false;
                }
            }
            else{
                col[child] = 1 - col[node];
                bool flag = bipartitionPossible(child, col, al);
                if(!flag){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> al[n + 1];
        
        for(int i = 0; i < dislikes.size(); i++){
            int a = dislikes[i][0], b = dislikes[i][1];
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        vector<int> col(n + 1, -1);
        
        for(int i = 1; i <= n; i++){
            if(col[i] == -1){
                col[i] = 0;
                if(!bipartitionPossible(i, col, al)){
                    return false;
                }
            }
        }
        return true;
    }
};
