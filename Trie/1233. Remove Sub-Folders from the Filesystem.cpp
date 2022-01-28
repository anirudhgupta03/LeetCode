class Solution {
public:
    bool static cmp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    struct TrieNode{
        unordered_map<char,TrieNode*> child;
        bool isEnd;
        TrieNode(){
            isEnd = false;
        }
    };
    bool solve(TrieNode* root, string &s){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]] == NULL){
                root -> child[s[i]] = new TrieNode();
            }
            root = root -> child[s[i]];
            if(root -> isEnd && (i == s.size() - 1 || s[i + 1] == '/')){
                return true;
            }
        }
        root -> isEnd = true;
        return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        
        TrieNode* root = new TrieNode();
        
        sort(folder.begin(), folder.end(), cmp);
        
        vector<string> res;
        
        for(int i = 0; i < folder.size(); i++){
            if(!solve(root, folder[i])){
                res.push_back(folder[i]);
            }
        }
        return res;
    }
};
