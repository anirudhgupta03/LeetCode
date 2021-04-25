class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        map<int,set<int>> m;
        
        for(int i = 0; i < logs.size(); i++){
            m[logs[i][0]].insert(logs[i][1]);
        }
        
        vector<int> ans(k,0);
        
        map<int,set<int>> :: iterator it;
        
        for(it = m.begin(); it != m.end(); it++){
            ans[(it->second).size()-1]++;
        }
        
        return ans;
    }
};
