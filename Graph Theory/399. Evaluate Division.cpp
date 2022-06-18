//Ref: https://www.youtube.com/watch?v=UcDZM6Ap5P4
//DFS
//Method - 1
class Solution {
public:
    double dfs(string start, string end, map<string,vector<pair<string,double>>> &mp, unordered_set<string> &vis){
        
        if(mp.find(start) == mp.end() || mp.find(end) == mp.end()){
            return -1.0;
        }
        vis.insert(start);
        
        if(start == end){
            return 1.0;
        }
        
        for(pair<string,double> x: mp[start]){
            string child = x.first;
            double val = x.second;
            if(vis.find(child) == vis.end()){
                double tempres = dfs(child, end, mp, vis);
                if(tempres != -1.0){
                    return tempres*val;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)     {
        
        map<string,vector<pair<string,double>>> mp;
        
        for(int i = 0; i < equations.size(); i++){
            string s1 = equations[i][0], s2 = equations[i][1];
            mp[s1].push_back({s2, values[i]});
            mp[s2].push_back({s1, 1.0/values[i]});
        } 
        
        vector<double> res;
        
        for(int i = 0; i < queries.size(); i++){
            string s1 = queries[i][0], s2 = queries[i][1];
            unordered_set<string> vis;
            res.push_back(dfs(s1, s2, mp, vis));
        }
        return res;
    }
};

//Method - 2
class Solution {
public:
    bool dfs(string curr, string end, double val, unordered_set<string> &vis, unordered_map<string,vector<pair<string,double>>> &al, double &ans){
        
        if(curr == end){
            ans = val;
            return true;
        }
        
        vis.insert(curr);
        
        for(auto &x: al[curr]){
            if(vis.find(x.first) == vis.end()){
                bool flag = dfs(x.first, end, val*x.second, vis, al, ans);
                if(flag) return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> al;
        
        for(int i = 0; i < equations.size(); i++){
            al[equations[i][0]].push_back({equations[i][1], values[i]});
            al[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        
        vector<double> res;
        
        for(auto &x: queries){
            if(al.find(x[0]) == al.end()){
                res.push_back(-1.0);
                continue;
            }
            if(x[0] == x[1]){
                res.push_back(1.0);
                continue;
            }
            double ans = -1.0;
            unordered_set<string> vis;
            dfs(x[0], x[1], 1.0, vis, al, ans);
            res.push_back(ans);
        }
        return res;
    }
};
