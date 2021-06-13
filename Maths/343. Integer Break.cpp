class Solution {
public:
    int integerBreak(int n) {
        
        if(n <= 2){
            return 1;
        }
        
        if(n == 3){
            return 2;
        }
        
        int p1 = n/3;
        
        if(n % 3 == 1){
            p1--;
        }
        
        int p2 = (n - p1*3)/2;
        
        int t1 = pow(3,p1);
        int t2 = pow(2,p2);
        
        return t1*t2;
    }
};
