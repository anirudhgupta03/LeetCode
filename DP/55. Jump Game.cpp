//Method - 1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        int dp[n];
        
        memset(dp,0,sizeof(dp));
        
        dp[0] = 1;
        
        int cov = 0;      // So far the current max index we can jump to.
        
        for(int i = 0; i < n - 1; i++){
            
            int jumpLen = nums[i];
            
            if(dp[i]){
                for(int j = cov + 1; j <= i + jumpLen; j++){
                    if(j < n)
                        dp[j] = 1;
                    else
                        break;
                }
                cov = max(cov,i + jumpLen);
            }
            else{
                return false;
            }

        }
        return dp[n-1];
    }
};

//Method - 2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int range = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(i <= range){
                range = max(range, i + nums[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};
