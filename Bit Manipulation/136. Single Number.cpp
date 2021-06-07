class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int xorsum = 0;
        
        for(auto x: nums){
            xorsum ^= x;
        }
        return xorsum;
    }
};
