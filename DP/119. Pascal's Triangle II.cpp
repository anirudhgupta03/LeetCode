//Approach - 1
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> dp(rowIndex + 1);
        
        dp[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            for(int j = i; j >= 0; j--){
                if(j == 0 || j == i) dp[j] = 1;
                else{
                    dp[j] = dp[j] + dp[j-1];
                }
            }
        }
        return dp;
    }
};

//Approach - 2
//Best Approach
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> dp(rowIndex + 1);
        
        long long val = 1;
        dp[0] = 1;
        
        for(int i = 1; i <= rowIndex; i++){
            val = val*(rowIndex - i + 1)/i;
            dp[i] = (int)val;
        }
        return dp;
    }
};
