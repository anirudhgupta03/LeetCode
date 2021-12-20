class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp(n + 1);
        
        dp[0] = 1;
        
        int ind1 = 0, ind2 = 0, ind3 = 0;
        
        for(int i = 1; i < n; i++){
            
            int ele = min({2*dp[ind1],3*dp[ind2],5*dp[ind3]});
            
            dp[i] = ele;
            
            if(2*dp[ind1] == ele){
                ind1++;
            }
            if(3*dp[ind2] == ele){
                ind2++;
            }
            if(5*dp[ind3] == ele){
                ind3++;
            }
        }
        return dp[n - 1];
    }
};
