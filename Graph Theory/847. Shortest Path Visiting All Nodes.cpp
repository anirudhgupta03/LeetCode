//Method - 1
class Solution {
public:
    #define piv pair<int,vector<int>>
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> vis(n, 0);
        
        queue<piv> q;
        
        for(int i = 0; i < n; i++){
            q.push({i,vis});
        }
        
        set<piv> vs;
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front().first;
                vis = q.front().second;
                q.pop();
                
                int count = 0;
                
                for(int i = 0; i < n; i++){
                    if(vis[i]) count++;
                }
                
                if(count == n){
                    return steps - 1;
                }
                
                if(vs.find({curr, vis}) != vs.end()) continue;
                vs.insert({curr, vis});
                
                for(int x: graph[curr]){
                    int temp = vis[x];
                    vis[x] = 1;
                    if(vs.find({x, vis}) == vs.end()){
                        q.push({x, vis});
                    }
                    vis[x] = temp;
                }
            }
            steps++;
        }
        return 0;
    }
};

//Method - 2
//Using Mask(Faster)
//Ref: https://www.youtube.com/watch?v=TmRk2F9L3Jw
class Solution {
public:
    #define pii pair<int,int>
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        int mask = 0;
        
        queue<pii> q;
        
        for(int i = 0; i < n; i++){
            q.push({i,mask});
        }
        
        set<pii> vis;
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front().first;
                mask = q.front().second;
                q.pop();
                
                if(mask == (1 << n) - 1){
                    return steps - 1;
                }
                
                if(vis.find({curr, mask}) != vis.end()) continue;
                vis.insert({curr, mask});
                
                for(int x: graph[curr]){
                    int temp = mask;
                    temp |= (1 << x);
                    if(vis.find({x, temp}) == vis.end()){
                        q.push({x, temp});
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
