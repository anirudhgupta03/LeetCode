class Solution {
public:
    string sortSentence(string s) {
        
        stringstream X(s);
        
        string temp;
        
        vector<string> v;
        
        int count = 0;
        
        while(X >> temp){
            v.push_back(temp);
        }
        
        for(int i = 0; i < v.size(); i++){
            reverse(v[i].begin(),v[i].end());
        }
        
        sort(v.begin(),v.end());
        
        for(int i = 0; i < v.size(); i++){
            reverse(v[i].begin(),v[i].end());
        }
        string ans;
        
        for(int i = 0; i < v.size(); i++){
            ans+= v[i].substr(0,v[i].size()-1);
            ans+= " ";
        }
        ans.pop_back();
        return ans;
    }
};
