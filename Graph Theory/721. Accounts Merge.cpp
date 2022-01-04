//Using DFS
class Solution {
public:
    void dfs(string email, vector<string> &emailList, unordered_map<string,bool> &visited, unordered_map<string, vector<string>> &graph){
        
        visited[email] = true;
        emailList.push_back(email);
        
        for(string emails: graph[email]){
            if(!visited[emails]){
                dfs(emails, emailList, visited, graph);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string,bool> visited;
        unordered_map<string, vector<string>> graph;
        unordered_map<string,string> emailNameRelation;
        
        for(int i = 0; i < accounts.size(); i++){
            int n = accounts[i].size();
            string name = accounts[i][0];
            emailNameRelation[accounts[i][1]] = name;
            visited[accounts[i][1]] = false;
            
            for(int j = 2; j < n; j++){
                visited[accounts[i][j]] = false;
                emailNameRelation[accounts[i][j]] = name;
                graph[accounts[i][j]].push_back(accounts[i][j-1]);
                graph[accounts[i][j-1]].push_back(accounts[i][j]);
            }
        }
        
        vector<vector<string>> res;
        
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                
                if(!visited[accounts[i][j]]){
                    vector<string> emailList;
                    dfs(accounts[i][j], emailList, visited, graph);
                    emailList.push_back(emailNameRelation[accounts[i][j]]);
                    
                    reverse(emailList.begin(),emailList.end());
                    sort(emailList.begin() + 1, emailList.end());
                    res.push_back(emailList);
                }
            }
        }
        return res;
    }
};
