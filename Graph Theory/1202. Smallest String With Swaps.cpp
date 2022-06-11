//Ref: https://www.youtube.com/watch?v=po4XuLCT9EA
//Method - 1
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

//Method - 2
class Solution {
public:
    void dfs(int node, int parent, vector<int> &par, vector<int> &vis, vector<char> &v, string &s, vector<int> al[]){
        
        par[node] = parent;
        v.push_back(s[node]);
        vis[node] = 1;
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(vis[child] == 0){
                dfs(child, parent, par, vis, v, s, al);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        
        vector<int> al[n];
        for(auto &x: pairs){
            al[x[0]].push_back(x[1]);
            al[x[1]].push_back(x[0]);
        }
        
        vector<vector<char>> temp(n);
        vector<int> par(n), vis(n, 0), ind(n, -1);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                vector<char> v;
                dfs(i, i, par, vis, v, s, al);
                sort(v.begin(), v.end());
                temp[i] = v;
                ind[i] = 0;
            }
        }
        
        string ans;
        for(int i = 0; i < n; i++){
            int parent = par[i];
            ans.push_back(temp[parent][ind[parent]]);
            ind[par[i]]++;
        }
        return ans;
    }
};
