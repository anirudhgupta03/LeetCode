//Method - 1
class Solution {
public:
    #define ll long long
    int solve(ll n, unordered_map<ll,int> &dp){
        
        if(n == 1){
            return 0;
        }
        
        if(dp.find(n) != dp.end()){
            return dp[n];
        }
        
        int op;
        if(n % 2 == 0){
            op = solve(n/2, dp) + 1;
        }
        else{
            op = min(solve(n - 1, dp), solve(n + 1, dp)) + 1;
        }
        return dp[n] = op;
    }
    int integerReplacement(int n) {
        
        unordered_map<ll,int> dp;
        
        return solve(n, dp);
    }
};

//Method - 2
class Solution {
public:
    #define ll long long
    #define pll pair<ll,ll>
    int integerReplacement(int n) {
        
        if(n == 1) return 0;
        
        queue<pll> q;
        
        q.push({n, 0});
        
        unordered_map<ll,ll> dp;
        
        int minsteps = INT_MAX;
        
        while(!q.empty()){
            
            ll ele = q.front().first, count = q.front().second;
            q.pop();
            
            if(ele == 1){
                minsteps = min(minsteps, (int)count);
                continue;
            }
            
            if(dp.find(ele) != dp.end()){
                continue;
            }
            dp[ele] = count;
            
            if(ele % 2 == 0){
                q.push({ele/2, count + 1});
            }
            else{
                q.push({ele + 1, count + 1});
                q.push({ele - 1, count + 1});
            }
        }
        return minsteps;
    }
};
