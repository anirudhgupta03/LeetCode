class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        ll tot = 0, sum = 0;
        int n = cost.size();
        
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++){
            v.push_back({nums[i], cost[i]});
        }
        
        sort(v.begin(), v.end());
        
        for(int i = 0; i < n; i++){
            sum += (ll)v[i].second;
        }
        
        ll median;
        int i = 0;
        
        while(tot < (sum + 1)/2 && i < n){
            tot += (ll)(v[i].second);
            median = v[i].first;
            i++;
        }
        
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(nums[i] - median)*(cost[i]);
        }
        return ans;
    }
};
