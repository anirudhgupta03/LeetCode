//Method - 1
//Using DFS
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

//Method - 2
//Using Topological Sort
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> indegree(n, 0), al[n];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                al[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            bool flag = false;
            while(sz--){
                
                int curr = q.front();
                q.pop();
                
                res.push_back(curr);
                
                for(int i = 0; i < al[curr].size(); i++){
                    int child = al[curr][i];
                    indegree[child]--;
                    if(indegree[child] == 0){
                        q.push(child);
                        flag = true;
                    }
                }
            }
            if(!flag) break;
        }
        sort(res.begin(),res.end());
        return res;
    }
};
