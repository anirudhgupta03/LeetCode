class Solution {
public:
    double calcPower(double x, long n){
        if(n < 0){
            return calcPower(1/x, abs(n));
        }
        if(n == 0) return 1;
        if(n == 1) return x;
        double val = myPow(x, n/2);
        if(n % 2 == 0){
            return val*val;
        }
        return x*val*val;
    }
    double myPow(double x, int n) {
        return calcPower(x, n);
    }
};
