//Ref: https://www.youtube.com/watch?v=vkPYz98YAD0
//Method - 1
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

//Method - 2
class Solution {
public:
    int dfs1(int node, int parent, vector<int> al[], vector<int> &heightSum, vector<int> &subTreeSize){
        
        int sum = 0;
        for(auto &x: al[node]){
            if(x != parent){
                sum += dfs1(x, node, al, heightSum, subTreeSize);
            }
        }
        heightSum[node] = sum;
        return sum + subTreeSize[node];
    }
    int dfs2(int node, int parent, vector<int> al[], vector<int> &subTreeSize){
        
        int size = 1;
        for(auto &x: al[node]){
            if(x != parent){
                size += dfs2(x, node, al, subTreeSize);
            }
        }
        return subTreeSize[node] = size;
    }
    void dfs3(int node, int parent, int n, vector<int> &res, vector<int> &heightSum, vector<int> &subTreeSize, vector<int> al[]){
        
        if(node == 0){
            res[node] = heightSum[node];
        }
        else{
            res[node] = heightSum[node];
            int thsum = res[parent];
            thsum = thsum - (heightSum[node] + subTreeSize[node]);
            res[node] += thsum + (n - subTreeSize[node]);
        }
        for(auto &x: al[node]){
            if(x != parent){
                dfs3(x, node, n, res, heightSum, subTreeSize, al);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> al[n];
        
        for(auto &x: edges){
            al[x[0]].push_back(x[1]);
            al[x[1]].push_back(x[0]);
        }
        
        
        vector<int> heightSum(n), subTreeSize(n);
        
        dfs2(0, -1, al, subTreeSize);
        dfs1(0, -1, al, heightSum, subTreeSize);
        
        vector<int> res(n);
        
        dfs3(0, -1, n, res, heightSum, subTreeSize, al);
        
        return res;
    }
};
