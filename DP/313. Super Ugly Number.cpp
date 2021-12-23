//Ref: https://www.youtube.com/watch?v=0FMKNDEopR0
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int dp[n];
        dp[0] = 1;
        
        int sz = primes.size();
        
        vector<int> ind(sz,0);
        
        for(int i = 1; i < n; i++){
            
            int mine = INT_MAX;
            for(int j = 0; j < sz; j++){
                mine = min(mine, primes[j]*dp[ind[j]]);
            }
            
            for(int j = 0; j < sz; j++){
                if(primes[j]*dp[ind[j]] == mine){
                    ind[j]++;
                }
            }
            dp[i] = mine;
        }
        return dp[n-1];
    }
};
