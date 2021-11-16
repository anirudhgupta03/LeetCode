//Ref: https://www.youtube.com/watch?v=cdQxSP6Dim8&t=14s
class Solution {
public:
    int findRemovals(string s){
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                st.push('(');
            }
            else if(s[i] == ')'){
                
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
        }
        
        return st.size();
    }
    
    void solve(vector<string> &res, string s, int removals, unordered_map<string,int> &umap){
        
        if(umap[s]){
            return;
        }
        
        umap[s] = true;
        
        if(removals == 0){
            
            int r = findRemovals(s);
            if(r == 0){
                res.push_back(s);
            }
            return;
        }
        
        for(int i = 0; i < s.size(); i++){
            
            string l = s.substr(0,i);
            string r = s.substr(i+1);
            string join = l + r;
            solve(res, join, removals - 1, umap);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        
        unordered_map<string,int> umap;
        
        int removals = findRemovals(s);
        
        vector<string> res;
        
        solve(res, s, removals, umap);
        
        return res;
    }
};
