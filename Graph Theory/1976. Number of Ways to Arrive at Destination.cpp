class Solution {
public:
    #define ll long long
    #define pll pair<ll,ll>
    struct cmp{
        bool operator()(pll p1, pll p2){
            return p1.second > p2.second;
        }
    };
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> al[n];
        
        for(int i = 0; i < roads.size(); i++){
            int ui = roads[i][0], vi = roads[i][1], timei = roads[i][2];
            al[ui].push_back({vi, timei});
            al[vi].push_back({ui, timei});
        }
        
        int mod = 1e9 + 7;
        
        vector<ll> timetaken(n, LLONG_MAX), ways(n, 0), vis(n, 0);
        
        ways[0] = 1;
        priority_queue<pll,vector<pll>,cmp> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            
            pll p = pq.top();
            pq.pop();
            
            ll curr = p.first, temptime = p.second;
            
            if(vis[curr]){
                continue;
            }
            vis[curr] = 1;
            
            if(curr == n - 1){
                return ways[curr];
            }
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i].first;
                if(vis[child] == 0){
                    if(temptime + al[curr][i].second < timetaken[child]){
                        timetaken[child] = temptime + al[curr][i].second;
                        ways[child] = ways[curr];
                        pq.push({child, timetaken[child]});
                    }
                    else if(temptime + al[curr][i].second == timetaken[child]){
                        ways[child] = (ways[child] + ways[curr])%mod;
                        
                    }
                }
            }
        }
        return ways[n - 1];
    }
};
