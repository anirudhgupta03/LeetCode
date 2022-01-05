class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        unordered_map<int,int> umap;
        int count = 0;
        
        bool flag = true;
        if(k == 0){
            
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] == nums[i-1] && flag){
                    count++;
                    flag = false;
                }
                else if(nums[i] != nums[i-1]){
                    flag = true;
                }
            }
            return count;
        }
        
        for(int i = 0; i < nums.size(); i++){
            
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            if(umap.find(nums[i] - k) != umap.end()){
                count++;
            }
            umap[nums[i]]++;
        }
        return count;
    }
};
