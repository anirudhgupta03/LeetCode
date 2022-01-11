//Ref: https://www.youtube.com/watch?v=ivl6BHJVcB0
//BFS
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> res;
        
        if(n == 1){
            res.push_back(0);
            return res;
        }
        vector<int> al[n];
        
        vector<int> degree(n, 0);
        
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            degree[a]++;
            degree[b]++;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        
        while(n > 2){
            int sz = q.size();
            n -= sz;
            
            while(sz--){
                int node = q.front();
                q.pop();
                for(int i = 0; i < al[node].size(); i++){
                    degree[al[node][i]]--;
                    if(degree[al[node][i]] == 1){
                        q.push(al[node][i]);
                    }
                }
            }
        }
    
        res.push_back(q.front());
        q.pop();
        if(!q.empty())
        res.push_back(q.front());
        return res;
    }
};
