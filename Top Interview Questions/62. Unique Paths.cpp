//Time Complexity - O(min(m,n))
//Space Complexity - O(1)
class Solution {
public:
    #define ll long long
    int uniquePaths(int m, int n) {
        
        int r = n - 1;
        int b = m - 1;
        
        int t = r + b;
        
        ll ans = 1;
        
        for(int i = 1; i <= min(r,b); i++){
            ans = ans*(t - i + 1);
            ans /= i;
        }
        
        return ans;
    }
};
