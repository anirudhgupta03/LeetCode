class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> umap1, umap2;
        for(int i = 0; i < s.length(); i++){
            if(umap1.find(s[i]) == umap1.end() && umap2.find(t[i]) == umap2.end()){
                umap1[s[i]] = t[i];
                umap2[t[i]] = s[i];
            }
            else if(umap1.find(s[i]) != umap1.end() && umap2.find(t[i]) != umap2.end()){
                if(umap1[s[i]] != t[i] || umap2[t[i]] != s[i]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
