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
