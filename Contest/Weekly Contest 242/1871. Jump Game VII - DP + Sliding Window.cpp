//Ref: https://leetcode.com/problems/jump-game-vii/discuss/1224936/DP-%2B-Sliding-Window-or-O(N)-or-Single-Pass
class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.size();
        
        if(s[n-1] == '1'){
            return false;
        }
        
        int dp[n];
        
        dp[0] = 1;
        
        int count = 0;
        
        for(int i = 1; i < s.size(); i++){
            
            if(i > maxJump){
                count -= dp[i-maxJump-1];
            }
            if(i >= minJump){
                count += dp[i-minJump];
            }
            
            if(count > 0 && s[i] == '0'){
                dp[i] = 1;
            }
            else{
                dp[i] = 0;
            }
        }
        
        return dp[n-1];
    }
};
