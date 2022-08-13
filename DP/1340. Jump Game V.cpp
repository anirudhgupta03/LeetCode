class Solution {
public:
    int solve(int ind, vector<int> &arr, int d, int n, vector<int> &dp){
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        int jumps = 1;
        for(int i = ind + 1; i <= min(n - 1, ind + d); i++){
            if(arr[ind] > arr[i]){
                jumps = max(jumps, solve(i, arr, d, n, dp) + 1);
            }
            else{
                break;
            }
        }
        for(int i = ind - 1; i >= max(0, ind - d); i--){
            if(arr[ind] > arr[i]){
                jumps = max(jumps, solve(i, arr, d, n, dp) + 1);
            }
            else{
                break;
            }
        }
        return dp[ind] = jumps;
    }
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        
        int ans = 0;
        vector<int> dp(n, -1);
        for(int i = 0; i < n; i++){
            ans = max(ans, solve(i, arr, d, n, dp));
        }
        return ans;
    }
};
