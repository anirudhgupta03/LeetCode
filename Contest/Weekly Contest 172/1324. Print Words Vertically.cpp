class Solution {
public:
    vector<string> printVertically(string s) {
        
        vector<string> v;
        
        stringstream X(s);
        
        string temp;
        
        while(X >> temp){
            v.push_back(temp);
        }
        
        for(int i = 0; i < v.size(); i++){
            cout << v[i].size() << " ";
        }
        
        int max_len = 0;
        
        for(int i = 0; i < v.size(); i++){
            if(v[i].size() > max_len){
                max_len = v[i].size();
            }
        }
        
        for(int i = 0; i < v.size(); i++){
            while(v[i].size() != max_len){
                v[i].push_back(' ');
                cout << 1;
            }
        }
        
        vector<string> res;
        
        for(int i = 0; i < max_len; i++){
            string ans;
            for(int j = 0; j < v.size(); j++){
                ans += v[j][i];
            }
            
            for(int j = ans.size() - 1; j >= 0; j--){
                if(ans[j] == ' '){
                    ans.pop_back();
                }
                else{
                    break;
                }
            }
            cout << ans << endl;
            res.push_back(ans);
        }
        
        return res;
    }
};
