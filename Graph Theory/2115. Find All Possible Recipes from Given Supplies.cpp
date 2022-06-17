//Ref: https://www.youtube.com/watch?v=kJ8peiAe7HE
//Method - 1
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string> available;
        
        for(int i = 0; i < supplies.size(); i++){
            available.insert(supplies[i]);
        }
        
         map<string,int> rem;
        
        for(int i = 0; i < recipes.size(); i++){
            rem[recipes[i]] = i;
        }
        
        bool flag = 1;
        
        vector<string> ans;
        
        while(flag){
            flag = 0;
            
            for(auto &x: rem){
                bool can = 1;
                for(int i = 0; i < ingredients[x.second].size(); i++){
                    if(available.find(ingredients[x.second][i]) == available.end()){
                        can = 0;
                        break;
                    }
                }
                if(can == 1){
                    available.insert(x.first);
                    ans.push_back(x.first);
                    rem.erase(x.first);
                    flag = 1;
                }
            }
        }
        return ans;
    }
};

//Method - 2
//Optimised Method - 1
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        
        vector<int> vis(n, 0);
        
        unordered_map<string,int> available;
        
        for(auto &x: supplies){
            available[x] = 1;
        }
        
        while(1){
            bool oflag = false;
            for(int i = 0; i < n; i++){
                if(vis[i] == 0){
                    bool flag = true;
                    for(auto &x: ingredients[i]){
                        if(available[x] == 0){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        oflag = true;
                        vis[i] = 1;
                        available[recipes[i]] = 1;
                    }
                }
            }
            if(!oflag) break;
        }
        vector<string> res;
        for(int i = 0; i < n; i++){
            if(vis[i]) res.push_back(recipes[i]);
        }
        return res;
    }
};

//Method - 3
//Topological Sorting
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string,vector<string>> graph;
        
        unordered_set<string> available;
        
        for(int i = 0; i < supplies.size(); i++){
            available.insert(supplies[i]);
        }
        
        unordered_map<string,int> indegree;
        
        for(int i = 0; i < recipes.size(); i++){
            indegree[recipes[i]] = 0;
        }
        
        for(int i = 0; i < recipes.size(); i++){
            for(int j = 0; j < (int)ingredients[i].size(); j++){
                if(available.find(ingredients[i][j]) == available.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        
        queue<string> q;
        for(auto x: indegree){
            if(x.second == 0){
                q.push(x.first);
            }
        }
        vector<string> ans;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto x: graph[curr]){
                    indegree[x]--;
                    if(indegree[x] == 0){
                        q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};

//Method - 4
//Ref: https://www.youtube.com/watch?v=yKi8TIZcQoU
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string, vector<string>> al;
        unordered_map<string,int> indegree;
        
        for(int i = 0; i < recipes.size(); i++){
            for(int j = 0; j < ingredients[i].size(); j++){
                al[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        queue<string> q;
        
        for(int i = 0; i < supplies.size(); i++){
            q.push(supplies[i]);
        }
        
        vector<string> res;
        
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            
            for(auto &x: al[curr]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};
