//Ref: https://www.youtube.com/watch?v=xf8qAkqDr8Y
class Solution {
public:
    void dfs(vector<int> &vis, int ind, int &count, int n){
        
        if(ind > n){
            count++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && ((ind % (i + 1) == 0) || (i + 1) % ind == 0)){
                vis[i] = ind;
                dfs(vis, ind + 1, count, n);
                vis[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> vis(n,0);
        int count = 0;
        dfs(vis, 1, count, n);
        return count;
    }
};
