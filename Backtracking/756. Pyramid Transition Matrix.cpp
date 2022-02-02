class Solution {
public:
    bool dfs(int ind, string bottom, vector<vector<string>> &mp, string &t){

        if(bottom.size() == 1){
            return true;
        }
        
        if(t.size() == bottom.size() - 1){
            string s = "";
            bool flag = dfs(0, t, mp, s);
            if(flag){
                return true;
            }
        }
        if(ind == bottom.size() - 1){
            return false;
        }
    
        string s = bottom.substr(ind, 2);
        int a = s[0] - 'A', b = s[1] - 'A';
        
        for(int i = 0; i < mp[a][b].size(); i++){
            t.push_back(mp[a][b][i]);
            bool flag = dfs(ind + 1, bottom, mp, t);
            if(flag){
                return true;
            }
            t.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        vector<vector<string>> mp(6, vector<string>(6,""));
        
        for(int i = 0; i < allowed.size(); i++){
            int a = allowed[i][0] - 'A', b = allowed[i][1] - 'A';
            mp[a][b].push_back(allowed[i][2]);
        }
        string t;
        return dfs(0, bottom, mp, t);
    }
};
