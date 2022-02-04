//Ref: https://leetcode.com/problems/shortest-path-with-alternating-colors/discuss/1370454/Easy-C%2B%2B-BFS-solution-oror-commented-oror-93-faster
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
