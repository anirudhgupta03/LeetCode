//Ref: https://www.youtube.com/watch?v=po4XuLCT9EA
class Solution {
public:
    int findp(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findp(par[node], par);
    }
    void unionp(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        
        vector<int> par(n);
        
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        
        for(int i = 0; i < pairs.size(); i++){
            
            int a = pairs[i][0], b = pairs[i][1];
            
            int para = findp(a, par);
            int parb = findp(b, par);
            
            if(para != parb){
                unionp(para, parb, par);
            }
        }
      
        for(int i = 0; i < n; i++){
            par[i] = findp(i, par);
        }
        
        map<int,vector<char>> mp;
        
        for(int i = 0; i < n; i++){
            mp[par[i]].push_back(s[i]);
        }
        
        for(auto x: mp){
            vector<char> v = x.second;
            sort(v.begin(), v.end());
            reverse(v.begin(),v.end());
            mp[x.first] = v;
        }
        
        string res;
        
        for(int i = 0; i < n; i++){
            res.push_back(mp[par[i]].back());
            mp[par[i]].pop_back();
        }
        return res;
    }
};
