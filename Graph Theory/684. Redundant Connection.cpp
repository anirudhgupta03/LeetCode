//Ref:https://www.youtube.com/watch?v=Cb6p18e9c8s
//DSU Ref: https://www.youtube.com/watch?v=3gbO7FDYNFQ
class Solution {
public:
    int findp(int node, vector<int> &par){
        
        if(par[node] < 0){
            return node;
        }
        return par[node] = findp(par[node], par);
    }
    void unionp(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        vector<int> par(n + 1);
        
        for(int i = 1; i <= n; i++){
            par[i] = -1;
        }
        
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            
            int a = edges[i][0], b = edges[i][1];
            
            int para = findp(a, par);
            int parb = findp(b, par);
            
            if(para == parb){
                res = {a,b};
                break;
            }
            else{
                unionp(para, parb, par);
            }
        }
        return res;
    }
};
