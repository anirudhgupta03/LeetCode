//Ref1: https://leetcode.com/problems/maximize-number-of-nice-divisors/discuss/1130512/Break-primeFactors-into-integers-to-maximize-products-or-Simple-solution-w-Explanation-O(logn)
//Ref2: https://leetcode.com/problems/maximize-number-of-nice-divisors/discuss/1130495/Python-O(log-n)-math-solution-explained
//Time Complexity : O(logN), required for modular exponentiation.
//Space Complexity : O(1)
class Solution {
public:
    #define ll long long
    ll power(ll base, ll expo, ll mod){
        
        if(expo == 0){
            return 1;
        }
        
        if(expo == 1){
            return base%mod;
        }
        
        ll temp;
        if(expo % 2 == 0){
            temp = power(base,expo/2,mod);
            return (temp*temp)%mod;
        }
        temp = power(base,(expo-1)/2,mod);
        return (((base*temp)%mod)*temp)%mod;
    }
    int maxNiceDivisors(int primeFactors) {
        
        if(primeFactors == 1){
            return 1;
        }
        
        int mod = 1e9 + 7;
        
        ll p1 = primeFactors/3;
        
        if(primeFactors % 3 == 1){
            p1--;
        }
        
        ll p2 = (primeFactors - p1*3)/2;
        
        ll t1 = power(3,p1,mod);
        ll t2 = power(2,p2,mod);
        
        return (t1*t2)%mod;
    }
};
