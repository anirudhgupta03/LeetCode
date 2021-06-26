class Solution {
public:
    bool isPalindrome(string s){
        
        int lo = 0, hi = s.size() - 1;
        
        while(lo < hi){
            if(s[lo] != s[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
    void solve(int ind, string s, vector<string> &temp, vector<vector<string>> &res){
        
        if(ind == s.size()){
            res.push_back(temp);
            return;
        }
        
        for(int i = ind; i < s.size(); i++){
            
            string t = s.substr(ind,i-ind+1);
            if(isPalindrome(t)){
                temp.push_back(t);
                solve(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> temp;
        
        solve(0,s,temp,res);
        
        return res;
    }
};
