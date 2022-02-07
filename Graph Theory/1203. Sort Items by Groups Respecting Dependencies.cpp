//Ref: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/discuss/1106701/C%2B%2B-Two-level-topological-sort.-Peel-off-the-tricky-parts-then-do-normal-TopoSort.
class Solution {
public:
    vector<int> topoSort(vector<unordered_set<int>> &graph, vector<int> &in){
        
        vector<int> order;
        
        queue<int> q;
        
        for(int i = 0; i < in.size(); i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            order.push_back(curr);
            
            for(int x: graph[curr]){
                in[x]--;
                if(in[x] == 0){
                    q.push(x);
                }
            }
        }
        
        for(int i = 0; i < in.size(); i++){
            if(in[i] > 0){
                return {};
            }
        }
        
        return order;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        for(int i = 0; i < n; i++){
            if(group[i] == -1){
                group[i] = m;
                m++;
            }
        }
        
        vector<int> res;
        
        vector<unordered_set<int>> graph1(m), graph2(n);
        vector<int> in1(m,0), in2(n,0);
        
        for(int i = 0; i < n; i++){
            int to_grp = group[i];
            for(int j = 0; j < beforeItems[i].size(); j++){
                // cout << beforeItems[i][j] << endl;
                int from_grp = group[beforeItems[i][j]];
                if(to_grp != from_grp && graph1[from_grp].find(to_grp) == graph1[from_grp].end()){
                    graph1[from_grp].insert(to_grp);
                    in1[to_grp]++;
                }
                if(graph2[beforeItems[i][j]].find(i) == graph2[beforeItems[i][j]].end()){
                    graph2[beforeItems[i][j]].insert(i);
                    in2[i]++;
                }
            }
        }
        
        vector<int> grporder = topoSort(graph1, in1);
        vector<int> itemorder = topoSort(graph2, in2);
        
        if(grporder.size() == 0 || itemorder.size() == 0){
            return {};
        }
        
        vector<vector<int>> grptoitem(m);
        
        for(auto x: itemorder){
            grptoitem[group[x]].push_back(x);
        }
        
        
        
        for(int grp_id: grporder){
            for(int item: grptoitem[grp_id]){
                res.push_back(item);
            }
        }
        
        return res;
    }
};
