class Solution {
public:
    #define ll long long
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<ll> indegree(n, 0);
        
        vector<pair<ll,ll>> v;
        
        for(int i = 0; i < roads.size(); i++){
            int a = roads[i][0], b = roads[i][1];
            indegree[a]++;
            indegree[b]++;
        }
        
        for(ll i = 0; i < n; i++){
            v.push_back({indegree[i], i});
        }
        
        sort(v.begin(), v.end());
        
        ll values[n];
        
        ll temp = n;
        
        for(ll i = v.size() - 1; i >= 0; i--){
            values[v[i].second] = temp;
            temp--;
        }
        
        ll sum = 0;
        
        for(ll i = 0; i < roads.size(); i++){
            sum += values[roads[i][0]] + values[roads[i][1]];
        }
        return sum;
    }
};
