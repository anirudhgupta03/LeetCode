class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int e1 = 1, e2 = 2, e3;
        
        for(int i = 3; i <= n; i++){
            e3 = e1 + e2;
            e1 = e2;
            e2 = e3;
        }
        return e3;
    }
};
