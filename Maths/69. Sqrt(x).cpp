class Solution {
public:
    #define ll long long
    int mySqrt(int x) {
        
        ll l = 0, r = x;
        
        int ans;
        
        while(l <= r){
            
            ll mid = (l + r)/2;
            
            if(mid*mid > x){
                r = mid - 1;
            }
            else if(mid*mid <= x){
                ans = mid;
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
