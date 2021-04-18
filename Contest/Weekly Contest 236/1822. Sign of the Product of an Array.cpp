class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int zero = 0, neg = 0;
        
        for(auto x : nums){
            
            if(x < 0) neg++;
            else if(x == 0) zero++;
        }
        
        if(zero != 0){
            return 0;
        }
        else{
            if(neg % 2 == 0){
                return 1;
            }
            else{
                return -1;
            }
        }
    }
};
