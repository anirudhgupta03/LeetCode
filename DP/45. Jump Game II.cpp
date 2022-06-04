//Method - 1
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        int dp[n];
        
        memset(dp,0,sizeof(dp));
        
        int cov = 0;
        
        for(int i = 0; i < n - 1; i++){
            
            for(int j = cov + 1; j <= i + nums[i]; j++){
                if(j < n)
                    dp[j] = dp[i] + 1;
                else
                    break;
            }
            cov = max(cov,nums[i]+i);
        }
        return dp[n-1];
    }
};

//Method - 2
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1){
            return 0;
        }
        
        int steps = nums[0], jumps = 1, range = nums[0];
        
        for(int i = 1; i < nums.size() - 1; i++){
            steps--;
            range = max(range, i + nums[i]);
            if(steps == 0){
                if(range <= i){
                    return -1;          //Not Possible To Reach 
                }
                jumps++;
                steps = range - i;
            }
        }
        return jumps;
    }
};
