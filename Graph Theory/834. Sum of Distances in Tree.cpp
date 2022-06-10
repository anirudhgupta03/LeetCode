//Ref: https://www.youtube.com/watch?v=vkPYz98YAD0
class Solution {
public:
    int dfs1(int curr, int par, vector<int> adj[], vector<int> &subtree){
        int temp = 0;
        for(int child: adj[curr]){
            if(child != par){
                temp += dfs1(child, curr, adj, subtree);
                temp += subtree[child];
                subtree[curr] += subtree[child];
            }
        }
        return temp;
    }
    void dfs2(int curr, int par, vector<int> adj[], vector<int> &res, vector<int> &subtree, int n, int result){
        res[curr] = result;
        for(int child: adj[curr]){
            if(child != par){
                dfs2(child, curr, adj, res, subtree, n, result - subtree[child] + subtree[0] - subtree[child]);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> res(n), subtree(n,1), adj[n];
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int rootans = dfs1(0, -1, adj, subtree);
        dfs2(0,-1,adj, res, subtree, n, rootans);
        return res;
    }
};
