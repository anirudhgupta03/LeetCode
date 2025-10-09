//Method - 1
class Solution {
public:
    
    void solve(int count1, int count2, string op, int n, vector<string> &v){
        
        if(count1 == n && count2 == n){
            v.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        if(count1 != n && count1 - count2 >=0){
            op1.push_back('(');
            op2.push_back(')');
            solve(count1+1,count2,op1,n,v);
            solve(count1,count2+1,op2,n,v);
        }
        else if(count1 == n){
            op1.push_back(')');
            solve(count1,count2+1,op1,n,v);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        
        int count1 = 1, count2 = 0;
        vector<string> v;
        
        string op;
        op.push_back('(');
        solve(count1,count2,op,n,v);
        
        return v;
    }
};

//Method - 2
class Solution {
public:
    void solve(string parentheses, int open, int close, int n, vector<string> &res){
        if(open + close == 2*n){
            res.push_back(parentheses);
            return;
        }
        if(open < n) solve(parentheses + "(", open + 1, close, n, res);
        if(close < open) solve(parentheses + ")", open, close + 1, n, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve("", 0, 0, n, res);
        return res;
    }
};
