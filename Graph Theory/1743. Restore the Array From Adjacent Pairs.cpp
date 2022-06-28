//Method - 1
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
//Method - 2
class Solution {
public:
    void solve(int curr, int par, unordered_map<int,vector<int>> &adj,vector<int> &res){
        
        res.push_back(curr);
        
        for(auto &x: adj[curr]){
            if(x != par){
                solve(x, curr, adj, res);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int, vector<int>> adj;
        unordered_map<int,int> indegree;
        
        for(auto &x: adjacentPairs){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
            indegree[x[1]]++;
        }
        
        int start;
        for(auto &x: indegree){
            if(x.second == 1){
                start = x.first;
                break;
            }
        }
        
        vector<int> res;
        solve(start, -1, adj, res);
        return res;
    }
};
