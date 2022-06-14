//Method - 1
class Solution {
public:
    int dfs(int node, int &mintime, vector<int> al[], vector<bool> &hasApple, vector<int> &vis){
        
        vis[node] = 1;
        int count = 0;
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(vis[child] == 0){
                int flag = dfs(child, mintime, al, hasApple, vis);
                if(flag){
                    count++;
                }
            }
        }
        
        if(hasApple[node] && node != 0){
            count++;
        }
        mintime += count;
        if(count){
            if(!hasApple[node] && node != 0){
                mintime++;
            }
            return 1;
        }
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        bool flag = false;
        for(int i = 0; i < hasApple.size(); i++){
            if(hasApple[i]){
                flag = true;
                break;
            }
        }
        if(!flag){
            return false;
        }
        int mintime = 0;
        
        vector<int> al[n];
        
        for(auto &x: edges){
            al[x[0]].push_back(x[1]);
            al[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        dfs(0, mintime, al, hasApple, vis);
        return mintime;
    }
};

//Method - 2
class Solution {
public:
    int solve(int node, int par, vector<int> al[], vector<bool> &hasApple){
        
        int sum = 0;
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(child != par){
                sum += solve(child, node, al, hasApple);
            }
        }
        if(hasApple[node] || sum) sum += 2;
        return sum;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<int> al[n];
        
        for(int i = 0; i < edges.size(); i++){
            al[edges[i][0]].push_back(edges[i][1]);
            al[edges[i][1]].push_back(edges[i][0]);
        }
        
        int ans = solve(0, -1, al, hasApple);
        if(ans) ans -= 2; 
        return ans;
    }
};
