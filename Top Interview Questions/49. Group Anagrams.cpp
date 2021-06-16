//Method - 1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>,vector<string>> mymap;
        
        for(int i = 0; i < strs.size(); i++){
            
            vector<int> alpha(26,0);
            
            for(int j = 0; j < strs[i].size(); j++){
                alpha[strs[i][j] - 'a']++;
            }
            
            mymap[alpha].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        
        for(auto x: mymap){
            res.push_back(x.second);
        }
        return res;
    }
};

//Method - 2
//Optimal Approach
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> myumap;
        
        for(int i = 0; i < strs.size(); i++){
            
            string s = strs[i];
            
            sort(s.begin(),s.end());
            
            myumap[s].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        
        for(auto x: myumap){
            res.push_back(x.second);
        }
        return res;
    }
};
