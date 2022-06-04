class Solution {
public:
    #define ll long long
    int uniquePaths(int m, int n) {
        
        m--;
        n--;
        
        ll paths = 1;
        
        for(int i = 1; i <= min(m,n); i++){
            paths *= (m + n - i + 1);
            paths /= i;
        }
        return paths;
    }
};
