//Method - 1
//Ref: https://www.youtube.com/watch?v=beOCN7G4h-M
class Solution {
public:
    void solve(int node, vector<int> al[], vector<int> &vis){
        
        vis[node] = 1;
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(vis[child] == 0){
                solve(child, al, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        vector<int> al[n];
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1]){
                    al[i].push_back(j);
                    al[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int cc_count = 0;
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                cc_count++;
                solve(i, al, vis);
            }
        }
        return n - cc_count;
    }
};

//Method - 2
class Solution {
public:
    int findPar(int node, vector<int>& par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findPar(par[node], par);
    }
    void merge(int nodeRow, int nodeCol, vector<int>& par){
        int parNodeRow = findPar(nodeRow, par);
        int parNodeCol = findPar(nodeCol, par);
        par[parNodeCol] = parNodeRow;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;
        for(auto &it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        vector<int> par(maxRow + maxCol + 2, -1);
        vector<int> size(maxRow + maxCol + 2, 0);
        
        for(int i = 0; i < maxRow + maxCol + 2; i++){
            par[i] = i;
        }
        unordered_set<int> stoneNodes;
        for(auto &it: stones){
            int nodeRow = it[0];
            int nodeCol = maxRow + it[1] + 1;
            merge(nodeRow, nodeCol, par);
            stoneNodes.insert(nodeRow);
            stoneNodes.insert(nodeCol);
        }
        int cnt = 0;
        for(auto &node: stoneNodes){
            if(findPar(node, par) == node){
                cnt++;
            }
        }
        return n - cnt;
    }
};
