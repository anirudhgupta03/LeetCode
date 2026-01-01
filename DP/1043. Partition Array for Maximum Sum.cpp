//Top-Down
//TC: O(N)
//SC: O(N*k) + Auxilliary Stack Space
class Solution {
public:
    int findMaxSumAfterPartitioning(int i, int k, vector<int>& arr, vector<int> &dp){
        if(i >= arr.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int maxSum = 0, maxVal = 0;
        for(int j = i; j < min(i + k, (int)arr.size()); j++){
            maxVal = max(maxVal, arr[j]);
            maxSum = max(maxSum, findMaxSumAfterPartitioning(j + 1, k, arr, dp) + (j - i + 1)*maxVal);
        }
        return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return findMaxSumAfterPartitioning(0, k, arr, dp);
    }
};

//Bottom-Up
//TC: O(N*k)
//SC: O(N)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            int maxSum = 0, maxVal = 0;
            for(int j = i; j < min(i + k, n); j++){
                maxVal = max(maxVal, arr[j]);
                maxSum = max(maxSum, dp[j + 1] + (j - i + 1)*maxVal);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};
