class MagicDictionary {
public:
    struct TrieNode{
        bool end;
        TrieNode* child[26];
        TrieNode(){
            end = false;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    TrieNode* root;
    MagicDictionary() {
        root = new TrieNode();
    }
    void insert(TrieNode* root, string s){
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                root -> child[s[i] - 'a'] = new TrieNode();
            }
            root = root -> child[s[i] - 'a'];
        }
        root -> end = true;
    }
    void buildDict(vector<string> dictionary) {
        for(int i = 0; i < dictionary.size(); i++){
            insert(root, dictionary[i]);
        }
    }
    bool solve(int ind, TrieNode* root, string s, int count){
        
        if(ind == s.size() && root -> end && count == 1){
            return true;
        }
        if(ind == s.size() || root == NULL){
            return false;
        }
        if(root -> child[s[ind] - 'a'] == NULL){
            if(count == 1){
                return false;
            }
        }
        for(int i = 0; i < 26; i++){
            if(root -> child[i] != NULL && i != (s[ind] - 'a')){
                bool flag = solve(ind + 1, root -> child[i], s, count + 1);
                if(flag){
                    return true;
                }
            }
            else if((i == s[ind] - 'a') && root -> child[s[ind] - 'a'] != NULL){
                bool flag = solve(ind + 1, root -> child[s[ind] - 'a'], s, count);
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
    bool search(string searchWord) {
        int count = 0;
        return solve(0, root, searchWord, count);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
