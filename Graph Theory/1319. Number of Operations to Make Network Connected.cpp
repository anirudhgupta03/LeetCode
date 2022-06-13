//Method - 1
class Solution {
public:
    void dfs(int node, int par, vector<int> al[], vector<int> &vis, int &count){
        
        vis[node] = 1;
        
        for(int i = 0; i < al[node].size(); i++){
            
            int child = al[node][i];
            
            if(vis[child] == 0){
                dfs(child,node,al,vis,count);
            }
            else{
                if(child != par){
                    count++;
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int cc_count = 0, b_count = 0;
        
        vector<int> vis(n,0);
        
        vector<int> al[n];
        
        for(int i = 0; i < connections.size(); i++){
            int a = connections[i][0], b = connections[i][1];
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        for(int i = 0; i < n; i++){
            
            if(!vis[i]){
                int count = 0;
                dfs(i,-1,al,vis,count);
                b_count += count;
                cc_count++;
            }
        }
      
        if(b_count/2 >= cc_count - 1){
            return cc_count - 1;
        }
        return -1;
    }
};

//Method - 2
//Ref1: https://leetcode.com/problems/number-of-operations-to-make-network-connected/discuss/717403/C%2B%2B-or-DFS-or-Number-of-Islands-or-Detailed-explanation
//Ref2: https://www.youtube.com/watch?v=kEXU1nP54NM
class Solution {
public:
    void dfs(int node, vector<int> al[], vector<int> &vis){
        
        vis[node] = 1;
        
        for(int i = 0; i < al[node].size(); i++){
            
            int child = al[node][i];
            
            if(vis[child] == 0){
                dfs(child,al,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1){
            return -1;
        }
        
        int cc_count = 0;
        
        vector<int> vis(n,0);
        
        vector<int> al[n];
        
        for(int i = 0; i < connections.size(); i++){
            int a = connections[i][0], b = connections[i][1];
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        for(int i = 0; i < n; i++){
            
            if(!vis[i]){
                dfs(i,al,vis);
                cc_count++;
            }
        }
        return cc_count - 1;
    }
};

//Method - 3
class Solution {
public:
    void unionP(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    int findP(int node, vector<int> &par){
        if(par[node] == -1){
            return node;
        }
        return par[node] = findP(par[node], par);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> par(n, -1);
        
        int extraCables = 0;
        
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0], v = connections[i][1];
            int paru = findP(u, par);
            int parv = findP(v, par);
            if(paru != parv){
                unionP(paru, parv, par);
            }
            else{
                extraCables++;
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(par[i] == -1){
                count++;
            }
        }
        count--;
        if(extraCables >= count){
            return count;
        }
        return -1;
    }
};
