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
    #define pipii pair<int,pair<int,int>>
    #define ll long long
    struct cmp{
        bool operator()(pipii p1, pipii p2){
            return p1.second.second > p2.second.second;
        }
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int dp[n];
        dp[0] = 1;
        
        priority_queue<pipii, vector<pipii>, cmp> pq;
        
        for(int i = 0; i < primes.size(); i++){
            pq.push({primes[i],{0,primes[i]}});
        }
        int ind = 1;
        
        while(ind != n){
            
            pipii p = pq.top();
            pq.pop();
            
            ll ele = p.first;
            ll ptr = p.second.first;
            ll val = p.second.second;
            
            if(val != dp[ind - 1]){
                dp[ind] = val;
                ind++;
            }
            
            ptr++;
            val = ele*dp[ptr];
            
            pipii temp = {ele,{ptr,val}};
            pq.push(temp);
        }
        return dp[n-1];
    }
};
