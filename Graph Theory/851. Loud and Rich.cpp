//Ref: https://www.youtube.com/watch?v=2VQftGT1gCQ
class Solution {
public:
    int dfs(int node, vector<int> &sol, vector<int> &quiet, vector<int> al[]){
        
        if(sol[node] != -1){
            return sol[node];
        }
        int minPos = node, minVal = quiet[node];
        for(int i = 0; i < al[node].size(); i++){
            int ind = dfs(al[node][i], sol, quiet, al);
            if(minVal > quiet[ind]){
                minVal = quiet[ind];
                minPos = ind;
            }
        }
        sol[node] = minPos;
        return minPos;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n = quiet.size();
        vector<int> al[n];
        
        for(int i = 0; i < richer.size(); i++){
            int a = richer[i][0], b = richer[i][1];
            al[b].push_back(a);
        }
      
        vector<int> sol(n, -1);
        for(int i = 0; i < n; i++){
            sol[i] = dfs(i, sol, quiet, al);
        }
        return sol;
    }
};
