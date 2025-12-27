//Intuition
int findTargetSumWaysTopDown(vector<int>& nums, int S) {
        
	int n = nums.size();
        int countOfZeroes = 0, sum = 0;

        for(auto &i:nums){
            sum += i;
            if(i==0)  countOfZeroes++;
        }

        /*
	we cant divided our array to have S diff,
        if even the totoal sum is < S 
	*/
	
        if(S > sum) return 0;
        if((S+sum)%2 != 0)  return 0;

        int s = (S+sum)/2;

        int dp[n+1][s+1];
        memset(dp, -1, sizeof dp);

        // initialization
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= s; i++)
            dp[0][i] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= s; j++){
                // we will avoid 0's, as we have already taken them into account
                if(nums[i-1] == 0 || j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
        }

        /*
            so adding or subtracting 0 won't make a difference to the total sum,
            but it can increase our number of subsets,
            as we can place them however we wish,
            so if we have n zeroes , than the total number of subsets formed = 2^n
            i.e if the count of subset s1 found in array is --> m,
            then the no. of subsets we can having n number of zeroes is --> m * 2^n

            ex : s1 = 3, and number of zeroes = 2;
            then we can have {0, s1}, {0, s1},  {0, 0, s1}, {0, 0, s1}
            now remember all these zeroes are at different indexes,
            so they will have different combinations
        */
        return (pow(2, countOfZeroes)*dp[n][s]);
    }

//Method 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int zeros = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        if(target > sum || target < -sum){
            return 0;
        }
        
        if((sum + target) % 2 != 0){
            return 0;
        }
        int s = (sum + target)/2;
        
        int dp[n + 1][s + 1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= s; j++){
                if(j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = 0;
                }
                else if(nums[i - 1] == 0 || nums[i - 1] > j){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
            }
        }
        return dp[n][s]*(1 << zeros);
    }
};

//Top-Down
class Solution {
public:
    int solve(int ind, int tsum, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(tsum == sum) return 1;
        if(tsum > sum || ind == nums.size()) return 0;
        if(dp[ind][tsum] != -1) return dp[ind][tsum];
        return dp[ind][tsum] = solve(ind + 1, tsum + nums[ind], sum, nums, dp) + solve(ind + 1, tsum, sum, nums, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int tsum = 0, zeros = 0;
        vector<int> vnums;
        for(int &ele: nums){
            tsum += ele;
            if(ele == 0) zeros++;
            else vnums.push_back(ele);
        }
		
        if(target > tsum || (tsum - target)%2 != 0) return 0;
        int sum = (tsum - target)/2;
        
        sort(vnums.begin(), vnums.end());
        int n = vnums.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        int ans = solve(0, 0, sum, vnums, dp);
        ans *= pow(2, zeros);
        return ans;
    }
};

//Tabulation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int tsum = 0, zeros = 0;
        vector<int> vnums;

        for(int &ele: nums){
            tsum += ele;
            if(ele == 0) zeros++;
            else vnums.push_back(ele);
        }

        sort(vnums.begin(), vnums.end());

        if(target > tsum || (tsum - target)%2 != 0) return 0;
        int sum = (tsum - target)/2;

        int n = vnums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        for(int ind = n; ind >= 0; ind--){
            for(int tsum = sum; tsum >= 0; tsum--){
                if(tsum == sum) dp[ind][tsum] = 1;
                else if(ind == n) dp[ind][tsum] = 0;
                else{
                    dp[ind][tsum] = dp[ind + 1][tsum];
                    if(tsum + vnums[ind] <= sum){
                        dp[ind][tsum] += dp[ind + 1][tsum + vnums[ind]];
                    }
                }
            }
        }
        int ans = dp[0][0];
        ans *= pow(2, zeros);
        return ans;
    }
};

//Tabulation + Space Optimization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int tsum = 0, zeros = 0;
        vector<int> vnums;

        for(int &ele: nums){
            tsum += ele;
            if(ele == 0) zeros++;
            else vnums.push_back(ele);
        }

        sort(vnums.begin(), vnums.end());

        if(target > tsum || (tsum - target)%2 != 0) return 0;
        int sum = (tsum - target)/2;

        int n = vnums.size();

        vector<int> prevDP(sum + 1, -1);

        for(int ind = n; ind >= 0; ind--){
            vector<int> currDP(sum + 1, -1);
            for(int tsum = sum; tsum >= 0; tsum--){
                if(tsum == sum) currDP[tsum] = 1;
                else if(ind == n) currDP[tsum] = 0;
                else{
                    currDP[tsum] = prevDP[tsum];
                    if(tsum + vnums[ind] <= sum){
                        currDP[tsum] += prevDP[tsum + vnums[ind]];
                    }
                }
            }
            prevDP = currDP;
        }
        int ans = prevDP[0];
        ans *= pow(2, zeros);
        return ans;
    }
};
