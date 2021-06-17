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
