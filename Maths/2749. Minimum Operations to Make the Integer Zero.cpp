//Ref: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/solutions/7157198/easy-mathematical-bitmanipulation-solution-with-clear-explanations
#define ll long long
class Solution {
public:
    int countSetBits(ll num){
        int cnt = 0;
        while(num){
            if(num % 2 == 1) cnt++;
            num /= 2;
        }
        return cnt;
    }
    int makeTheIntegerZero(int num1, int num2) {
        int x = 1;
        while(true){
            ll val1 = (ll)num1 - ((ll)x*num2);
            if(val1 < x){
                break;
            }
            int sb = countSetBits(val1);
            if(sb <= x){
                return x;
            }
            x++;
        }
        return -1;
    }
};
