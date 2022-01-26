//Ref: https://www.youtube.com/watch?v=FTRvh4U1xsg
class StreamChecker {
public:
    struct TrieNode{
        bool isEnd;
        TrieNode* child[26];
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    void insert(TrieNode* root, string &s){
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                root -> child[s[i] - 'a'] = new TrieNode();
            }
            root = root -> child[s[i] - 'a'];
        }
        root -> isEnd = true;
    }
    string s;
    TrieNode* root;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            string key = words[i];
            reverse(key.begin(), key.end());
            insert(root, key);
        }
    }
    bool search(TrieNode* root, string &s){
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(root -> child[s[i] - 'a'] == NULL){
                return false;
            }
            root = root -> child[s[i] - 'a'];
            if(root -> isEnd) return true;
        }
        return root -> isEnd;
    }
    bool query(char letter) {
        s.push_back(letter);
        return search(root, s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
