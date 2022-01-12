class Solution {
public:
    void solve(int n, int node, vector<int> &temp, vector<vector<int>> &res, vector<vector<int>> &graph, vector<int> &vis){
        
        if(node == n - 1){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < graph[node].size(); i++){
            int child = graph[node][i];
            if(vis[child] == 0){
                vis[child] = 1;
                temp.push_back(child);
                solve(n, child, temp, res, graph, vis);
                temp.pop_back();
                vis[child] = 0;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> res;
        vector<int> temp;
        
        temp.push_back(0);
        vector<int> vis(graph.size(), 0);
        vis[0] = 1;
        solve(graph.size(), 0, temp, res, graph, vis);
        return res;
    }
};
