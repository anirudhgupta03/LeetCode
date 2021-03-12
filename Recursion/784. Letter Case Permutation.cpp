class Solution {
public:
    
    void solve(string ip,string op,vector<string> &v){
        
        if(ip == ""){
            v.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        if(isalpha(ip[0])){
            op1.push_back(toupper(ip[0]));
            op2.push_back(tolower(ip[0]));
            ip.erase(ip.begin());
            solve(ip,op1,v);
            solve(ip,op2,v);
        }
        else{
            op1.push_back(ip[0]);
            ip.erase(ip.begin());
            solve(ip,op1,v);
        }
        return;
    }
    vector<string> letterCasePermutation(string S) {
        
        string op = "";
        vector<string> v;
        
        solve(S,op,v);
        return v;
    }
};
