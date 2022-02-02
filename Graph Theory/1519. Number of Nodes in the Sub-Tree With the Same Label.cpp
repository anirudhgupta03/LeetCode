class Solution {
public:
    vector<int> solve(int node, vector<int> al[], vector<int> &res, string &labels, vector<int> &vis){
        
        vis[node] = 1;
        
        vector<int> alpha(26, 0);
        alpha[labels[node] - 'a'] = 1;
        for(int i = 0; i < al[node].size(); i++){
            if(vis[al[node][i]]) continue;
            vector<int> v = solve(al[node][i], al, res, labels, vis);
            for(int j = 0; j < 26; j++){
                alpha[j] += v[j];
            }
        }
        res[node] = alpha[labels[node] - 'a'];
        return alpha;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int> res(n, 1);
        
        vector<int> al[n];
        
        vector<int> vis(n, 0);
        
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        solve(0, al, res, labels, vis);
        
        return res;
    }
};
