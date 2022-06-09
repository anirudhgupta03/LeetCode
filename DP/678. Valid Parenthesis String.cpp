//Method - 1
//TC - O(N*N)
//SC - O(N*N)
class Solution {
public:
    bool solve(int sum, int ind, string &s, vector<vector<int>> &dp){
        
        if(ind == s.size() && sum == 0){
            return true;
        }
        
        if(ind == s.size() || sum < 0){
            return false;
        }
        
        if(dp[sum][ind] != -1){
            return dp[sum][ind];
        }
        
        if(s[ind] == '('){
            bool flag = solve(sum + 1, ind + 1, s, dp);
            if(flag) return true;
        }
        else if(s[ind] == ')'){
            bool flag = solve(sum - 1, ind + 1, s, dp);
            if(flag) return true;
        }
        else{
            bool flag = solve(sum, ind + 1, s, dp) || solve(sum + 1, ind + 1, s, dp) || solve(sum - 1, ind + 1, s, dp);
            if(flag) return true;
        }
        return dp[sum][ind] = false;
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, - 1));
        return solve(0, 0, s, dp);
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=KuE_Cn3xhxI
//TC - O(N)
//SC - O(N)
class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> open, star;
        int len = s.size();
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        
        while(!open.empty()){
            if(star.empty()){
                return false;
            }
            else if(open.top() < star.top()){
                open.pop();
                star.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};

//Method - 3
//TC - O(N)
//SC - O(1)
//Ref: https://www.youtube.com/watch?v=2H9gMIIGyvY
class Solution {
public:
    bool checkValidString(string s) {
        
        int balance = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                balance--;
            }
            else{
                balance++;
            }
            if(balance < 0) return false;
        }
        if(balance == 0) return true;
        
        balance = 0;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '('){
                balance--;
            }
            else{
                balance++;
            }
            if(balance < 0) return false;
        }
        return true;
    }
};
