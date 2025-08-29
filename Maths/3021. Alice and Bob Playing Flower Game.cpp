#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {

        ll evensn = n/2;
        ll oddsn = (n + 1)/2;
        
        ll evensm = m/2;
        ll oddsm = (m + 1)/2;

        return (evensn*oddsm + oddsn*evensm); 
    }
};
