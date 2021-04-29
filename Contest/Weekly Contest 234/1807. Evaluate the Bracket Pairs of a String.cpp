class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string,string> umap;
        
        for(int i = 0; i < knowledge.size(); i++){
            umap[knowledge[i][0]] = knowledge[i][1];
        }
        string ans;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                i++;
                string temp;
                while(i < s.size() && s[i] != ')'){
                    temp.push_back(s[i]);
                    i++;
                }
                
                if(umap.find(temp) != umap.end()){
                    ans+= umap[temp];
                }    
                else{
                    ans.push_back('?');
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};
