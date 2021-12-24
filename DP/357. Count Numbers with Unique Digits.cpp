class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 10;
        }
        
        vector<pair<int,int>> dp(n + 1);
        dp[1] = {9,0};
        
        for(int i = 2; i <= n; i++){
            int tr = (dp[i-1].first)*(i-1) + (dp[i-1].second)*10;
            int diff = pow(10,i) - pow(10,i-1);
            int tu = diff - tr;
            dp[i] = {tu, tr};
        }
        
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += dp[i].first;
        }
        sum += 1;
        return sum;
    }
};
