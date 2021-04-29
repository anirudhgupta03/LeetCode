//Ref: https://leetcode.com/problems/count-nice-pairs-in-an-array/discuss/1140487/Count-Frequency-of-difference-of-number-and-its-reverse-or-Easy-Hashmap-Explained
class Solution {
public:
    #define ll long long
    ll rev(int cur){
        
        ll ans = 0;
        
        while(cur){
            ans = 10*ans + cur%10;
            cur /= 10;
        }
        
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        
        ll mod = 1e9 + 7;
        
        unordered_map<ll,ll> umap;
        
        for(int i = 0; i < nums.size(); i++){
            
            ll reverse = rev(nums[i]);
            
            umap[nums[i] - reverse]++;
            
        }
        
        unordered_map<ll,ll> :: iterator it;
        
        ll ans = 0;
        
        for(it = umap.begin(); it != umap.end(); it++){
            ans += ((it->second)*(it->second-1))/2;
        }
        
        return ans%mod;
    }
};
