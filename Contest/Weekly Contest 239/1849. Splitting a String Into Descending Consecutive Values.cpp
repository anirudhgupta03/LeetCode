class Solution {
public:
    void solve(int ind, double last, vector<string> &temp, vector<vector<string>> &v, string &s){
        
        if(ind == s.size()){
            v.push_back(temp);
            return;
        }

        for(int i = ind; i < s.size(); i++){
                if(last == -1)
                {
                    temp.push_back(s.substr(ind,i-ind+1));
                    double val = stod(s.substr(ind,i-ind+1));
                    solve(i+1,val,temp,v,s);
                    temp.pop_back();
                }
                else
                {
                    double val = stod(s.substr(ind,i-ind+1));
                    if(val + 1 == last)
                    {
                        temp.push_back(s.substr(ind,i-ind+1));
                        solve(i+1,val,temp,v,s);
                        temp.pop_back();
                    }
                }
        }
    }
    bool splitString(string s) {
        
        vector<vector<string>> v;
        vector<string> temp;

        solve(0,-1,temp,v,s);

       if(v.size()> 1) return true;
        return false;
    }
};
