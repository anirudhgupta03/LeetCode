//Ref: https://www.youtube.com/watch?v=Rl4PznQDz3o
class Solution {
public:
    #define ll long long
    
    ll lcm(ll a, ll b){
        return (a*b)/__gcd(a,b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        
        ll lo = 1, hi = 2*(1e9);
        
        ll ans;
        
        while(lo <= hi){
            
            ll mid = (lo + hi)/2;
            
            ll temp = (mid/a) + (mid/b) + (mid/c) - (mid/lcm(a,b)) - (mid/lcm(a,c)) - mid/lcm(b,c) + (mid/(lcm(a, lcm(b,c))));
            
            if(temp < n){
                lo = mid + 1;
            }
            else{
                if(mid % aa == 0 || mid % bb == 0 || mid % cc == 0){
                    ans = mid;
                }
                hi = mid - 1;
            }
        }
        return ans;
    }
};
