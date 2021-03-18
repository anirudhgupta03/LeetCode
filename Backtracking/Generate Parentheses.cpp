class Solution {
public:
    
    void solve(string &s, vector<string> &v, int count1, int count2, int n){
        
        if(count1 == n && count2 == n){
            v.push_back(s);
            return;
        }
        
        if(count1 != n){
            s.push_back('(');
            solve(s,v,count1+1,count2,n);
            s.pop_back();
        }
        if(count1 > count2){
            s.push_back(')');
            solve(s,v,count1,count2+1,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> v;
        string s;
        
        solve(s,v,0,0,n);
        
        return v;
    }
};
