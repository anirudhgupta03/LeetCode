//Method - 1
class Solution {
public:
    #define pid pair<int,double>
    void dfs(int node, int parent, vector<int> al[], unordered_map<int,int> &par, vector<int> &vis){
        
        vis[node] = 1;
        par[node] = parent;
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(vis[child] == 0){
                dfs(child, node, al, par, vis);
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        vector<int> al[n + 1];
        
        for(auto &x: edges){
            int u = x[0], v = x[1];
            al[u].push_back(v);
            al[v].push_back(u);
        }
        
        unordered_map<int,int> par;
        vector<int> vis(n + 1, 0);
        dfs(1, -1, al, par, vis);
        
        for(int i = 0; i <= n; i++){
            vis[i] = 0;
        }
        
        queue<pid> q;
        q.push({1,1.0});
        
        vector<double> probability(n + 1, -1);
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front().first;
                double prob = q.front().second;
                q.pop();
                
                if(curr == target && t == 0){
                    return prob;
                }
                if(vis[curr]) continue;
                vis[curr] = 1;
                
                int child = al[curr].size() - 1;
                if(curr == 1) child++;
                
                bool flag = false;
                for(int i = 0; i < al[curr].size(); i++){
                    if(al[curr][i] == par[curr]) continue;
                    if(vis[al[curr][i]] == 0){
                        q.push({al[curr][i], prob*(1.0/child)});
                        flag = true;
                    }
                }
                if(!flag){
                    probability[curr] = prob;
                }
            }
            t--;
            if(t == -1) break;
        } 
        
        if(probability[target] != -1){
            return probability[target];
        }
        return 0;
    }
};

//Method - 2
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        vector<int> al[n + 1];
        
        for(auto &x: edges){
            al[x[0]].push_back(x[1]);
            al[x[1]].push_back(x[0]);
        }
        
        queue<pair<int,double>> q;
        q.push({1,1.0});
        
        vector<int> vis(n + 1, 0);
        
        t++;
        while(!q.empty() && t--){
            int sz = q.size();
            while(sz--){
                int curr = q.front().first;
                double prob = q.front().second;
                q.pop();

                vis[curr] = 1;
                
                int temp = al[curr].size() - 1;
                if(curr == 1) temp++;
                
                if(curr == target){
                    if(t == 0 || temp == 0){
                        return prob;
                    }
                    else{
                        return 0;
                    }
                }
                
                for(int i = 0; i < al[curr].size(); i++){
                    int child = al[curr][i];
                    if(vis[child] == 0){
                        q.push({child, prob/temp});
                    }
                }
            }
        }
        return 0;
    }
};
