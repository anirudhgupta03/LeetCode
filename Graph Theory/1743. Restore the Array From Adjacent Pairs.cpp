
class Solution {
public:
    void dfs(map<int,vector<int>> &m, set<int> &s, int head, vector<int> &ans){
    
    if(s.find(head)!=s.end())
        return;
    s.insert(head);
    ans.push_back(head);
    
    for(auto u : m[head]){
        dfs(m,s,u,ans);
    }
    
}
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        map<int, vector<int>> m;
        
        for(int i = 0; i < adjacentPairs.size(); i++){
            m[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        
        int head;
        for(auto pr : m){
            if(pr.second.size() == 1){
                head = pr.first;
            }
        }
        
        set<int> s;
        vector<int> ans;
        
        dfs(m,s,head,ans);
        
        return ans;
    }
};
