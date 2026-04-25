//Method - 1
class Solution {
public:
    int solve(int ind, int sum, string &s, vector<vector<int>> &dp){
        
        if(ind == s.size() && sum == 0){
            return 1;
        }
        if(ind == s.size() || sum < 0){
            return 0;
        }
        
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }
        int flag;
        if(s[ind] == '('){
            flag = solve(ind + 1, sum + 1, s, dp);
        }
        else if(s[ind] == ')'){
            flag = solve(ind + 1, sum - 1, s, dp);
        }
        else{
            flag = solve(ind + 1, sum + 1, s, dp) || solve(ind + 1, sum, s, dp) || solve(ind + 1, sum - 1, s, dp);
        }
        return dp[ind][sum] = flag;
    }
    bool checkValidString(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1,-1));
        return solve(0, 0, s, dp);
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=cHT6sG_hUZI
class Solution {
public:
    bool checkValidString(string s) {
        
        int minSum = 0, maxSum = 0;

        for(char ch: s){
            if(ch == '('){
                minSum++;
                maxSum++;
            }
            else if(ch == ')'){
                minSum = max(0, minSum - 1);
                maxSum--;
                if(maxSum < 0){
                    return false;
                }
            }
            else if(ch == '*'){
                minSum = max(0, minSum - 1);
                maxSum++;
            }
        }
        return minSum == 0;
    }
};
