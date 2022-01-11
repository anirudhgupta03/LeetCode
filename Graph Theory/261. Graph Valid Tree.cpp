class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool cycleExists(int node, int par, vector<int> &vis, vector<int> al[]){
        
        vis[node] = 1;
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(vis[child]){
                if(child != par)
                return true;
            }
            else{
                bool flag = cycleExists(child, node, vis, al);
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>> &edges) {
        
        if(edges.size() != n - 1){
            return false;
        }

        vector<int> al[n];

        for(int i = 0; i < n - 1; i++){
            int a = edges[i][0], b = edges[i][1];
            al[a].push_back(b);
            al[b].push_back(a);
        }

        vector<int> vis(n , 0);
        bool flag = false;
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                if(flag){
                    return false;
                }
                else{
                    flag = true;
                    if(cycleExists(i,-1,vis,al)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
