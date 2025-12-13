//Method - 1
class Solution {
public:
    void dfs(int node, vector<int> al[], vector<int> &vis){
        vis[node] = 1;
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(!vis[child]){
                dfs(child, al, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> al[n];
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j]){
                    al[i].push_back(j);
                    al[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, al, vis);
                count++;
            }
        }
        return count;
    }
};

//Method - 2
//Using DSU
class Solution {
public:
    int findPar(int node, vector<int>& par){
        if(par[node] == node) return node;
        return par[node] = findPar(par[node], par);
    }
    void merge(int node1, int node2, vector<int>& par){
        par[node2] = node1;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> par(n, -1);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j]){
                    int pari = findPar(i, par);
                    int parj = findPar(j, par);
                    if(pari != parj){
                        merge(pari, parj, par);
                    }
                }
            }
        }
        int provinces = 0;
        for(int i = 0; i < n; i++){
            if(par[i] == i) provinces++;
        }
        return provinces;
    }
};
