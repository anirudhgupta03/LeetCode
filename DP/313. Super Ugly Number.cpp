//Ref: https://www.youtube.com/watch?v=0FMKNDEopR0
//Method - 1
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

//Method - 2
class Solution {
public:
    #define ll long long
    struct cmp{
      bool operator()(vector<ll> &v1, vector<ll> &v2){
          return v1[2] > v2[2];
      }  
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int dp[n + 1];
        
        priority_queue<vector<ll>, vector<vector<ll>>, cmp> pq;
        
        for(int i = 0; i < primes.size(); i++){
            pq.push({primes[i], 1, primes[i]});
        }
        
        dp[1] = 1;
        int i = 2;
        
        while(i <= n){
            ll ele = pq.top()[0], ptr = pq.top()[1], val = pq.top()[2];
            pq.pop();
            
            if(val != dp[i - 1]){
                dp[i] = val;
                i++;
            }
            ptr++;
            pq.push({ele, ptr, ele*dp[ptr]});
        }
        return dp[n];
    }
};
