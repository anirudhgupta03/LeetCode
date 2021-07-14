class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        
        unordered_set<int> us;
        
        for(auto x: nums){
            us.insert(x);
        }
        
        int maxLen = 1;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(us.find(nums[i] - 1) == us.end()){
                
                int currLen = 1;
                int currNum = nums[i];
                
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
