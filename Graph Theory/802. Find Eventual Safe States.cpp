class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int node, vector<int> &vis, unordered_set<int> &safe_nodes, unordered_set<int> &cycle_nodes){
        
        if(safe_nodes.find(node) != safe_nodes.end()){
            return true;
        }
        if(cycle_nodes.find(node) != cycle_nodes.end()){
            return false;
        }
        
        if(vis[node]){
            cycle_nodes.insert(node);
            return false;
        }
        
        vis[node] = 1;
        
        for(int i = 0; i < graph[node].size(); i++){
            int child = graph[node][i];
            bool flag = dfs(graph, child, vis, safe_nodes, cycle_nodes);
            if(!flag){
                cycle_nodes.insert(node);
                return false;
            }
        }
        safe_nodes.insert(node);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int> ans;
        unordered_set<int> safe_nodes, cycle_nodes;
        
        int n = graph.size();
        vector<int> vis(n,0);
        
        for(int i = 0; i < n; i++){
            bool flag = dfs(graph, i, vis, safe_nodes, cycle_nodes);
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};
