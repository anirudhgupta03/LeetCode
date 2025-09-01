//Ref: https://www.youtube.com/watch?v=oO5uLE7EUlM&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=13
//Method - 1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> us;
        for(auto &x: nums){
            us.insert(x);
        }
        int maxLen = 1;
        for(auto it: us){
            if(us.find(it - 1) == us.end()){
                int currLen = 1;
                int currNum = it;
                while(us.find(currNum + 1) != us.end()){
                    currLen++;
                    currNum++;
                }
                maxLen = max(maxLen,currLen);
            }
        }
        return maxLen;
    }
};

//Method - 2
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
