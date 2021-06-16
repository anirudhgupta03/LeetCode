class Solution {
public:
    #define ll long long
    int divide(int dividend, int divisor) {
        
        int sign = 1;
        
        if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0){
            sign = -1;
        }
        
        ll m = abs(dividend), n = abs(divisor);
        
        ll q = 0, t = 0;
        
        for(ll i = 31; i >= 0; i--){
            
            if(t + (n << i) <= m){
                t += (n << i);
                q += (1LL << i);
            }
        }
        
        q = sign*q;
        
        if(q < INT_MIN || q > INT_MAX){
            return INT_MAX;
        }
        
        return q;
    }
};
