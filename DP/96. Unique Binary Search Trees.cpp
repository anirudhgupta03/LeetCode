//Catalan Number
class Solution {
public:
    int numTrees(int n) {
        
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            
            int l = 0, r = i - 1;
            while(l <= i - 1){
                dp[i] += dp[l]*dp[r];
                l++;
                r--;
            }
        }
        
        return dp[n];
    }
};
