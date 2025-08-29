class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int num: nums){
            umap[num] = 1;
        }
        int ans = 0;
        for(auto &tnum: umap){
            int num = tnum.first;
            if(umap[num] == 0){
                continue;
            }
            int ele = num - 1, len = 1;
            while(umap.find(ele) != umap.end() && umap[ele]){
                len += umap[ele];
                umap[ele] = 0;
                ele--;
            }
            umap[num] = len;
            ans = max(ans, len);
        }
        return ans;
    }
};
