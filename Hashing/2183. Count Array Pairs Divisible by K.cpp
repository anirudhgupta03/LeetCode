//Ref: https://www.youtube.com/watch?v=BleZpyLbjGg
class Solution {
public:
    #define ll long long
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        ll ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int x = __gcd(nums[i], k);
            int req = k/x;
            for(auto it: umap){
                if(it.first % req == 0){
                    ans += it.second;
                }
            }
            umap[x]++;
        }
        return ans;
    }
};
