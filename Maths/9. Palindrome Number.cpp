#define ll long long
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        ll rev = 0;
        ll tx = x;
        while(tx){
            rev = 10*rev + tx%10;
            tx /= 10;
        }
        return (rev == x);
    }
};
