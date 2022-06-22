class Solution {
public:
    void solve(int ind, vector<int> &path, vector<vector<int>> &allpath, vector<vector<int>> &graph){
        if(ind == graph.size() - 1){
            allpath.push_back(path);
            return;
        }
        for(auto &x: graph[ind]){
            path.push_back(x);
            solve(x, path, allpath, graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> allpath;
        path.push_back(0);
        solve(0, path, allpath, graph);
        return allpath;
    }
};
