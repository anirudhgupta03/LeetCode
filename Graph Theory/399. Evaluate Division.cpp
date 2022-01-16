//Ref: https://www.youtube.com/watch?v=UcDZM6Ap5P4
//DFS
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
