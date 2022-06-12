class Solution {
public:
    bool isValid(string x, string y){
    
    int count = 0;
    for(int i = 0; i < x.size(); i++){
        
        if(x[i] != y[i]){
            count++;
        }
    }
    
    if(count == 1) return true;
    return false;
    }
    int ladderLength(string A, string B, vector<string>& C) {
        
        if(find(C.begin(),C.end(),B) == C.end()){
            return 0;
        }
        C.push_back(A);
        
        int dst;
        
        for(int i = 0; i < C.size(); i++){
            
            if(C[i] == B){
                dst = i;
            }
        }
        int n = C.size();
    
        vector<int> al[n];
        
        for(int i = 0; i < n; i++){
        
            string x = C[i];
        
        for(int j = i + 1; j < C.size(); j++){
            
            string y = C[j];
            
            if(isValid(x,y)){
                al[i].push_back(j);
                al[j].push_back(i);
            }
        }
    }
    
    queue<int> q;
    q.push(n-1);
    
    vector<int> dist(n);
    vector<int> vis(n,0);
    
    dist[n-1] = 1;
    vis[n-1] = 1;
    
    while(!q.empty()){
        
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        
        for(int i = 0; i < al[curr].size(); i++){
            
            int child = al[curr][i];
            
            if(vis[child] == 0){
                
                dist[child] = dist[curr] + 1;
                q.push(child);
                vis[child] = 1;
                
            }
        }
    }
    return dist[dst];
    }
};

//BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> words;
        
        for(string s: wordList){
            words[s]++;
        }
        
        if(words[endWord] == 0){
            return 0;
        } 
        
        int steps = 1;
        queue<string> q;
        q.push(beginWord);
        
        unordered_set<string> vis;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                
                if(curr == endWord){
                    return steps;
                }
                
                if(vis.find(curr) != vis.end()){
                    continue;
                }
                vis.insert(curr);
                
                for(int i = 0; i < curr.size(); i++){
                    char ch = curr[i];
                    for(int j = 0; j < 26; j++){
                        if(j == ch - 'a') continue;
                        curr[i] = j + 'a';
                        if(vis.find(curr) == vis.end() && words[curr]){
                            q.push(curr);
                        }
                        curr[i] = ch;
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};

//BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> us;
        
        for(auto &x: wordList){
            us.insert(x);
        }
        
        if(us.find(endWord) == us.end()){
            return 0;
        }
        
        int steps = 1;
        queue<string> q;
        q.push(beginWord);
        
        unordered_set<string> vis;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                
                if(curr == endWord){
                    return steps;
                }
                
                if(vis.find(curr) != vis.end()) continue;
                vis.insert(curr);
                
                for(int i = 0; i < curr.size(); i++){
                    char c = curr[i];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(ch == c) continue;
                        curr[i] = ch;
                        if(us.find(curr) != us.end() && vis.find(curr) == vis.end()){
                            q.push(curr);
                        }
                    }
                    curr[i] = c;
                }
            }
            steps++;
        }
        return 0;
    }
};
