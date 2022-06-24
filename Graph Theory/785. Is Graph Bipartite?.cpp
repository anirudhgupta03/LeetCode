//Method - 1
class Solution {
public:
    bool dfs(int node, int color, vector<int> &vis, vector<int> &col, vector<vector<int>> &graph){
        
        vis[node] = 1;
        col[node] = color;
        
        for(int i = 0; i < graph[node].size(); i++){
            int child = graph[node][i];
            if(vis[child]){
                if(col[child] == color){
                    return false;
                }
            }
            else{
                bool flag = dfs(child, 1 - color, vis, col, graph);
                if(!flag){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> vis(n, 0), col(n, -1);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                bool flag = dfs(i, 0, vis, col, graph);
                if(!flag){
                    return false;
                }
            }
        }
        return true;
    }
};

//Method - 2
class Solution {
public:
    bool check(int node, int col, vector<int> &color, vector<vector<int>> &graph){
        
        color[node] = col;
        
        for(int i = 0; i < graph[node].size(); i++){
            int child = graph[node][i];
            
            if(color[child] != -1){
                if(color[child] == color[node]){
                    return false;
                }
            }
            else{
                bool flag = check(child, 1 - col, color, graph);
                if(!flag) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
    
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                bool flag = check(i, 1, color, graph);
                if(!flag) return false;
            }
        }
        return true;
    }
};
