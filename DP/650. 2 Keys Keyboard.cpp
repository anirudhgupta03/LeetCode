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

//Alternate Approach
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
