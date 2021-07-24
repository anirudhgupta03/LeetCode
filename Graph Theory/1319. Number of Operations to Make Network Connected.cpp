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
//Ref: https://leetcode.com/problems/number-of-operations-to-make-network-connected/discuss/717403/C%2B%2B-or-DFS-or-Number-of-Islands-or-Detailed-explanation
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
