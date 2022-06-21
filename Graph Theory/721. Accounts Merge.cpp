//Method - 1
//Iterative
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        
        vector<int> visited(n, 0);
        
        vector<vector<string>> res;
        
        vector<unordered_map<string,int>> help(n);
        
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                help[i][accounts[i][j]] = 1;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            
            unordered_set<string> vis;
            vector<string> acc;
            acc.push_back(accounts[i][0]);
            
            for(int j = 1; j < accounts[i].size(); j++){
                if(vis.find(accounts[i][j]) == vis.end()){
                    acc.push_back(accounts[i][j]);
                    vis.insert(accounts[i][j]);
                }
            }
            int ind = 1;
            
            while(ind < acc.size()){
                
                for(int j = i + 1; j < n; j++){
                    if(visited[j]) continue;
                    
                    if(accounts[j][0] == accounts[i][0]){
                        bool flag = false;
                        if(help[j].find(acc[ind]) != help[j].end()){
                            visited[j] = 1;
                            for(int k = 1; k < accounts[j].size(); k++){
                                if(vis.find(accounts[j][k]) == vis.end()){
                                    acc.push_back(accounts[j][k]);
                                    vis.insert(accounts[j][k]);
                                }
                            }
                        }
                    }
                }
                ind++;
            }
            sort(acc.begin() + 1, acc.end());
            res.push_back(acc);
        }
        return res;
    }
};

//Method - 2
//Using DFS
//Recursive
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
