//BFS
class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int> &nodeColor){
        queue<int> q;
        q.push(node);
        nodeColor[node] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &child: graph[curr]){
                if(nodeColor[child] == -1){
                    nodeColor[child] = 1 - nodeColor[curr];
                    q.push(child);
                }
                else if(nodeColor[child] == nodeColor[curr]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> nodeColor(n, -1);
        for(int i = 0; i < n; i++){
            if(nodeColor[i] == -1){
                if(!bfs(i, graph, nodeColor)){
                    return false;
                }
            }
        }
        return true;
    }
};

//DFS
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
