//Method - 1
class Solution {
public:
    int solve(int m, vector<int> &dp){
        if(m == 0){
            return 1;
        }
        if(dp[m] != -1){
            return dp[m];
        }
        int maxProd = 1;
        for(int i = 1; i <= m; i++){
            maxProd = max(maxProd, i*solve(m - i, dp));
        }
        return dp[m] = maxProd;
    }
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        int maxProd = 1;
        for(int i = 1; i < n; i++){
            maxProd = max(maxProd, i*solve(n - i, dp));
        }
        return maxProd;
    }
};

//Method - 2
class Solution {
public:
    int integerBreak(int n) {
        
        if(n <= 2){
            return 1;
        }
        
        if(n == 3){
            return 2;
        }
        
        int p1 = n/3;
        
        if(n % 3 == 1){
            p1--;
        }
        
        int p2 = (n - p1*3)/2;
        
        int t1 = pow(3,p1);
        int t2 = pow(2,p2);
        
        return t1*t2;
    }
};
