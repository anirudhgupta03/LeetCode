class Solution {
public:
    int findPar(int node, vector<int>& par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findPar(par[node], par);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> umap;
        vector<int> par(n, -1);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        for(int i = 0; i < n; i++){
            vector<string> emails = accounts[i];
            for(int j = 1; j < emails.size(); j++){
                if(umap.find(emails[j]) == umap.end()){
                    umap[emails[j]] = i;
                }
                else{
                    int paru = findPar(par[i], par);
                    int parv = findPar(umap[emails[j]], par);
                    par[parv] = paru;
                }
            }
        }
        for(int i = 0; i < n; i++){
            par[i] = findPar(i, par);
        }
        unordered_map<int,vector<string>> mp;
        vector<vector<string>> res;
        for(auto &x: umap){
            auto[str, u] = x;
            mp[par[u]].push_back(str);
        }
        for(auto &x: mp){
            vector<string> vec = x.second;
            sort(vec.begin(), vec.end());
            vec.insert(vec.begin(), accounts[x.first][0]);
            res.push_back(vec);
        }
        return res;
    }
};
