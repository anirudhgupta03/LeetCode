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
