#define ll long long
class Solution {
public:
    int reverse(int x) {
        ll rev = 0;
        while(x){
            rev = 10*rev + x % 10;
            x = x/10;
        }
        if(rev < INT_MIN || rev > INT_MAX){
            return 0;
        }
        return (int)rev;
    }
};
