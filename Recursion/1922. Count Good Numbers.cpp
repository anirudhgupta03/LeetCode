class Solution {
public:
    int mod = 1e9 + 7;
    long long myPow(int base, long long pow){
        if(pow == 0) return 1;
        if(pow == 1) return base;
        long long val = myPow(base, pow/2);
        if(pow % 2 == 0) return (val*val)%mod;
        return (base*val*val)%mod;
    }
    int countGoodNumbers(long long n) {
        long long evenPower = (n + 1)/2;
        long long oddPower = n/2;
        return ((myPow(5, evenPower) % mod)*(myPow(4, oddPower) % mod))%mod;
    }
};
