class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
      
        TrieNode* child[26];
        bool wordend;
        TrieNode(){
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
            wordend = false;
        }
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        TrieNode* temp = root;
        
        for(int i = 0; i < word.size(); i++){
            if(temp -> child[word[i] - 'a'] == NULL){
                temp -> child[word[i] - 'a'] = new TrieNode();
            }
            temp = temp -> child[word[i] - 'a'];
        }
        temp -> wordend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode* temp = root;
        
        for(int i = 0; i < word.size(); i++){
            if(temp -> child[word[i] - 'a'] == NULL){
                return false;
            }
            temp = temp -> child[word[i] - 'a'];
        }
        
        if(temp -> wordend == true){
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode* temp = root;
        
        for(int i = 0; i < prefix.size(); i++){
            if(temp -> child[prefix[i] - 'a'] == NULL){
                return false;
            }
            temp = temp -> child[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
