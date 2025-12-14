class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int findPar(int node, vector<int>& par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findPar(par[node], par);
    }
    void merge(int node1, int node2, vector<int> &par, vector<int> &islandSize){
        if(node1 != node2){
            if(islandSize[node1] >= islandSize[node2]){
                par[node2] = node1;
                islandSize[node1] += islandSize[node2];
            }
            else{
                par[node1] = node2;
                islandSize[node2] += islandSize[node1];
            }
        }
    }
    int findSizeOfIsland(int i, int j, vector<int> &size, vector<vector<int>> &grid, vector<int> &par){
        unordered_set<int> adjParents;
        for(int k = 0; k < 4; k++){
            int di = i + dx[k], dj = j + dy[k];
            if(di >= 0 && dj >= 0 && di < grid.size() && dj < grid[0].size() && grid[di][dj]){
                adjParents.insert(findPar(di*grid[0].size() + dj, par));
            }
        }
        int sz = 1;
        for(auto &parent: adjParents){
            sz += size[parent];
        }
        return sz;
    }   
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> islandSize(n*n, 1);
        vector<int> par(n*n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                par[n*i+j] = n*i + j;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj]){
                        int nodePar = findPar(n*i + j, par);
                        int adjNodePar = findPar(n*ni + nj, par);
                        merge(nodePar, adjNodePar, par, islandSize);
                    }
                }
            }
        }
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    ans = max(ans, findSizeOfIsland(i, j, islandSize, grid, par));
                }
            }
        }
        for(int i = 0; i < n*n; i++){
            if(grid[i/n][i%n]){
                ans = max(ans, islandSize[i]);
            }
        }
        return ans;
    }
};
