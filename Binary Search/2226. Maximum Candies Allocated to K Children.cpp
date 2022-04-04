class Solution {
public:
    #define ll long long
    bool isPossible(ll mid, vector<int> &candies, ll k){
        
        ll count = 0;
        for(ll i = 0; i < candies.size(); i++){
            if(mid <= candies[i]){
                count += candies[i]/mid;
            }
        }
        if(count >= k){
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        ll sum = 0;
        
        for(int x: candies){
            sum += x;
        }
        
        if(sum < k){
            return 0;
        }
        
        ll lo = 1, hi = sum/k;
        ll ans;
        
        while(lo <= hi){
            ll mid = (lo + hi)/2;
            if(isPossible(mid, candies, k)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
