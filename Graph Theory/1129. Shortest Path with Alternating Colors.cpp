//Ref: https://leetcode.com/problems/shortest-path-with-alternating-colors/discuss/1370454/Easy-C%2B%2B-BFS-solution-oror-commented-oror-93-faster
//Method - 1
//Using BFS
class Solution {
public:
    #define ppiii pair<pair<int,int>,int>
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<int> alR[n], alB[n];
        
        for(auto &x: redEdges){
            int u = x[0], v = x[1];
            alR[u].push_back(v);
        }
        
        for(auto &x: blueEdges){
            int u = x[0], v = x[1];
            alB[u].push_back(v);
        }
        
        queue<ppiii> q;
        
        vector<pair<int,int>> res(n, {INT_MAX,INT_MAX});    //red,blue
        
        res[0] = {0,0};
        
        q.push({{0,1},0});
        q.push({{0,2},0});
        
        while(!q.empty()){
            
            ppiii p = q.front();
            q.pop();
            
            int curr = p.first.first, color = p.first.second, level = p.second;
            
            if(color == 1){
                for(int i = 0; i < alB[curr].size(); i++){
                    int child = alB[curr][i];
                    if(res[child].second > level + 1){
                        q.push({{child, 2}, level + 1});
                        res[child].second = level + 1;
                    }
                }
            }
            else{
                for(int i = 0; i < alR[curr].size(); i++){
                    int child = alR[curr][i];
                    if(res[child].first > level + 1){
                        q.push({{child, 1}, level + 1});
                        res[child].first = level + 1;
                    }
                }
            }
        }
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            ans[i] = min(res[i].first, res[i].second);
            if(ans[i] == INT_MAX) ans[i] = -1;
        }
        return ans;
    }
};

//Method - 2
class Solution {
public:
    #define pii pair<int,int>
    void solve(int len, int node, int edgeColor, vector<pair<int,int>> al[], vector<vector<int>> &dist){
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i].first, color = al[node][i].second;
            if(color != edgeColor && len + 1 < dist[child][color]){
                dist[child][color] = len + 1;
                solve(len + 1, child, color, al, dist);
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<pair<int,int>> al[n];
        
        for(auto &x: redEdges){
            al[x[0]].push_back({x[1],0});
        }
        
        for(auto &x: blueEdges){
            al[x[0]].push_back({x[1],1});
        }
        
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        
        dist[0][0] = dist[0][1] = 0;
        solve(0, 0, -1, al, dist);
        
        vector<int> ans(n);
                                 
        for(int i = 0; i < n; i++){
            if(dist[i][0] == INT_MAX && dist[i][1] == INT_MAX){
                ans[i] = -1;
            }
            else{
                ans[i] = min(dist[i][0], dist[i][1]);
            }
        }
        return ans;
    }
};
