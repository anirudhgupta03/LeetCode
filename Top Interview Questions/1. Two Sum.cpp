//Ref: https://www.youtube.com/watch?v=UXDSeD9mN-k&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0ny
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> umap;
        
        vector<int> res;
        
        for(int i = 0 ; i < nums.size(); i++){
            
            if(umap.find(target-nums[i]) != umap.end()){
                res.push_back(i);
                res.push_back(umap[target-nums[i]]);
                break;
            }
            
            umap[nums[i]] = i;
        }
        
        return res;
    }
};
