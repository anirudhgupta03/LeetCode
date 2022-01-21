//Ref: https://www.youtube.com/watch?v=WuBTG71yOek
class Solution {
public:
    bool isSimilar(string s1, string s2){
        
        int count = 0;
        
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                count++;
            }
            if(count > 2){
                return false;
            }
        }
        return true;
    }
    void dfs(string s, vector<string> &strs, unordered_set<string> &vis){
        
        vis.insert(s);
        
        for(int i = 0; i < strs.size(); i++){
            if(vis.find(strs[i]) == vis.end()){
                if(isSimilar(s, strs[i])){
                    dfs(strs[i], strs, vis);
                }
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        
        int count = 0;
        
        unordered_set<string> vis;
        
        for(int i = 0; i < strs.size(); i++){
            if(vis.find(strs[i]) == vis.end()){
                count++;
                dfs(strs[i], strs, vis);
            }
        }
        return count;
    }
};
