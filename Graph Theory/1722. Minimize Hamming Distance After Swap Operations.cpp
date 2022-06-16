class Solution {
public:
    void unionp(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    int findp(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findp(par[node], par);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();
        
        vector<int> par(n);
        
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        
        for(auto &x: allowedSwaps){
            
            int u = x[0], v = x[1];
            
            int paru = findp(u, par);
            int parv = findp(v, par);
            
            if(paru != parv){
                unionp(paru, parv, par);
            }
        }
        for(int i = 0; i < n; i++){
            par[i] = findp(i, par);
        }
        
        int count = 0;
        unordered_map<int,unordered_map<int,int>> mp;
        
        for(int i = 0; i < n; i++){
            mp[par[i]][source[i]]++;;
        }
        
        for(int i = 0; i < n; i++){
            if(mp[par[i]][target[i]] != 0){
                mp[par[i]][target[i]]--;
            }
            else{
                count++;
            }
        }
        return count;
    }
};
