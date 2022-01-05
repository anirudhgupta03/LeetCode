class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int n = sqrt(c);
        
        int lo = 0, hi = n;
        
        for(int i = 0; i <= n; i++){
            
            int temp = c - i*i;
            
            int t = sqrt(temp);
            
            if(t*t == temp){
                return true;
            }
        }
        return false;
    }
};
