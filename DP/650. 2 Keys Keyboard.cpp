//Top-Down
//TC: O(n*n)
//SC: O(n*n) + Auxilliary Stack Space
class Solution {
public:
    int solve(int count, int copy, int n, vector<vector<int>> &dp){
        
        if(count == n){
            return 0;
        }
        
        if(dp[count][copy] != -1){
            return dp[count][copy];
        }
        int minSteps = INT_MAX;
        
        if(copy){
            if(count + copy <= n){
                int temp = solve(count + copy, copy, n, dp);
                if(temp != INT_MAX)
                minSteps = min(minSteps, temp + 1); 
            }
        }
        if(2*count <= n){
            int temp = solve(2*count, count, n, dp);
            if(temp != INT_MAX)
            minSteps = min(minSteps, temp + 2);
        }
        return dp[count][copy] = minSteps;
    }
    int minSteps(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, 0, n, dp);
    }
};

//Method - 1
class Solution {
public:
    void solve(bool flag, int count, int copied, int steps, int &minsteps, int n){
        
        if(count == n){
            minsteps = min(minsteps, steps);
            return;
        }
        
        if(count + copied <= n){
            solve(false, count + copied, copied, steps + 1, minsteps, n);
        }
        if(!flag){
            solve(true, count, count, steps + 1, minsteps, n);
        }
    }
    int minSteps(int n) {
        
        if(n == 1){
            return 0;
        }
        int steps = 1, minsteps = INT_MAX;
        int count = 1, copied = 1;
        
        bool flag = true;
        solve(flag, count, copied, steps, minsteps, n);
        
        return minsteps;
    }
};

//Method - 2
class Solution {
public:
    int minSteps(int n) {
        
       int dp[n + 1];
        
        dp[1] = 0;
        
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0){
                dp[i] = dp[i/2] + 2;
            }
            else{
                int ans = i;
                for(int j = 3; j <= sqrt(i); j += 2){
                    if(i % j == 0){
                        ans = min(ans, dp[j] + i/j);
                        ans = min(ans, dp[i/j] + j);
                    }
                }
                dp[i] = ans;
            }
        }
        return dp[n];
    }
};

//Method - 3
//Optimal Approach
//Ref: https://www.youtube.com/watch?v=anHoebBokmg
class Solution {
public:
    int minSteps(int n) {
        
        int ans = 0;
        
        for(int i = 2; i*i <= n; ){
            
            if(n % i == 0){
                ans += i;
                n /= i;
            }
            else{
                i++;
            }
        }
        
        if(n != 1){
            ans += n;
        }
        
        return ans;
    }
};
