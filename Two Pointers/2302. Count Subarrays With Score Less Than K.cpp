class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n = nums.size();
        
        ll count = 0;
        
        vector<ll> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        ll lo = 0, hi = 0, sum = 0;
        
        while(hi < n){
            sum = (prefix[hi + 1] - prefix[lo])*(hi - lo + 1);
            if(sum >= k){
                while(sum >= k && lo <= hi){
                    lo++;
                    sum = (ll)(prefix[hi + 1] - prefix[lo])*(hi - lo + 1);
                }
            }
            hi++;
            count += (hi - lo);
        }
        return count;
    }
};
