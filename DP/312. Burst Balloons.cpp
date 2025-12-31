//Expert Problem
//Top-Down
class Solution {
public:
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int max = INT_MIN;
        
        for(int k = i; k <= j - 1; k++){
            
            int temp1;
            if(dp[i][k] != -1) temp1 = dp[i][k];
            else               temp1 = solve(nums, i, k, dp);
            
            int temp2;
            if(dp[k+1][j] != -1) temp2 = dp[k+1][j];
            else                 temp2 = solve(nums, k + 1, j, dp);
            
            int tempans = temp1 + temp2 + nums[i-1]*nums[k]*nums[j];
            if(tempans > max){
                max = tempans;
            }
        }
        return dp[i][j] = max;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        return solve(nums, 1, nums.size() - 1,dp);
    }
};

//Top-Down
//TC: O(n*n*n)
//SC: O(n*n) + Auxilliary Stack Space
class Solution {
public:
    int findMaxCoins(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
       
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxCoins = INT_MIN;
        
        for(int k = i; k <= j; k++){
            int left = (i - 1 >= 0) ? nums[i - 1] : 1;
            int right = (j + 1 < nums.size()) ? nums[j + 1] : 1;
            
            int leftR = findMaxCoins(i, k - 1, nums, dp);
            int rightR = findMaxCoins(k + 1, j, nums, dp);
            
            if(leftR != INT_MIN && rightR != INT_MIN){
                maxCoins = max(maxCoins, left*nums[k]*right + leftR + rightR);
            }
        }
        return dp[i][j] = maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findMaxCoins(0, n - 1, nums, dp);
    }
};

//Bottom-Up
//TC: O(n*n*n)
//SC: O(n*n)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, - 1));
        
        for(int lo = n - 1; lo >= 1; lo--){
            for(int hi = lo; hi <= n - 1; hi++){
                int maxcoins = 0;
                for(int i = lo; i < hi; i++){
                    maxcoins = max(maxcoins, dp[lo][i] + dp[i + 1][hi] + nums[lo - 1]*nums[i]*nums[hi]);
                }
                dp[lo][hi] = maxcoins;
            }
        }
        return dp[1][n - 1];
    }
};
