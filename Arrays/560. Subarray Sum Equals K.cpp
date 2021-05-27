class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int currsum = 0;
        
        unordered_map<int,int> umap;
        
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            currsum += nums[i];
            
            if(currsum == k){
                count++;
            }
            
            if(umap.find(currsum-k) != umap.end()){
                count += umap[currsum-k];
            }
            
            umap[currsum]++;
        }
        
        return count;
    }
};
