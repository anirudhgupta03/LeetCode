//Method - 1
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<unordered_map<int,int>> dp(n);
        
        int ans = 2;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int x = nums[i] - nums[j];
                dp[i][x] = dp[j].count(x)?dp[j][x]+1:2;  
                ans=max(dp[i][x],ans);
            }
        }
        return ans;
    }
};

//Method - 2
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<unordered_map<int,int>> v(n);
        
        vector<int> dp(n,0);
        
        int ans = 0;
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                
                int diff = nums[i] - nums[j];
                
                if(v[i][diff] == 0){
                    if(v[j][diff] == 0){
                        dp[i] = max(dp[i], 2);
                        v[i][diff] = 2;
                    }
                    else{
                        dp[i] = max(dp[i], v[j][diff] + 1);
                        v[i][diff] = v[j][diff] + 1;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
