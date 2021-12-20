//Approach - 1
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
        vector<int> res;
        
        for(int i = 0; i < expression.size(); i++){
            char c = expression[i];
            
            if(c == '-' || c == '+' || c == '*'){
                string s1 = expression.substr(0,i);
                string s2 = expression.substr(i+1);
                vector<int> v1 = diffWaysToCompute(s1);
                vector<int> v2 = diffWaysToCompute(s2);
                
                for(int i = 0; i < v1.size(); i++){
                    for(int j = 0; j < v2.size(); j++){
                        if(c == '-'){
                            res.push_back(v1[i] - v2[j]);
                        }
                        else if(c == '+'){
                            res.push_back(v1[i] + v2[j]);
                        }
                        else{
                            res.push_back(v1[i] * v2[j]);
                        }
                    }
                }
            }
        }
        if(res.size() == 0) res.push_back(stoi(expression));
        return res;
    }
};

//Approach - 2
//Optimal Approach
class Solution {
public:
    vector<int> solve(string expression, unordered_map<string,vector<int>> &dp){
        
        if(dp.find(expression) != dp.end()){
            return dp[expression];
        }
        vector<int> res;
        
        for(int i = 0; i < expression.size(); i++){
            char c = expression[i];
            
            if(c == '-' || c == '+' || c == '*'){
                string s1 = expression.substr(0,i);
                string s2 = expression.substr(i+1);
                vector<int> v1 = solve(s1, dp);
                vector<int> v2 = solve(s2, dp);
                
                for(int i = 0; i < v1.size(); i++){
                    for(int j = 0; j < v2.size(); j++){
                        if(c == '-'){
                            res.push_back(v1[i] - v2[j]);
                        }
                        else if(c == '+'){
                            res.push_back(v1[i] + v2[j]);
                        }
                        else{
                            res.push_back(v1[i] * v2[j]);
                        }
                    }
                }
            }
        }
        if(res.size() == 0) res.push_back(stoi(expression));
        return dp[expression] = res;
    }
    vector<int> diffWaysToCompute(string expression) {
        
        unordered_map<string,vector<int>> dp;
        
        return solve(expression, dp);
    }
};
