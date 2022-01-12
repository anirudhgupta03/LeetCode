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
