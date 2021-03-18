class Solution {
public:
    
    void solve(string &s,string &S, vector<string> &v, int ind){
        
        if(ind == S.size()){
            v.push_back(s);
            return;
        }
        
        if(isalpha(S[ind])){
            s.push_back(tolower(S[ind]));
            solve(s,S,v,ind+1);
            s.pop_back();
            s.push_back(toupper(S[ind]));
            solve(s,S,v,ind+1);
            s.pop_back();
        }
        else{
        s.push_back(S[ind]);
           solve(s,S,v,ind+1);
            s.pop_back();
        }
    
    }
    vector<string> letterCasePermutation(string S) {
        
        string s;
        
        vector<string> v;
        
        solve(s,S,v,0);
        
        return v;
    }
};
