//Ref: https://www.youtube.com/watch?v=xvNwoz-ufXA&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=17
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, sum = 0;
        unordered_map<int,int> umap;
        umap[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(umap.find(sum - k) != umap.end()){
                ans += umap[sum - k];
            }
            umap[sum]++;
        }
        return ans;
    }
};
