//Using Trie + DFS
class WordDictionary {
public:
    struct TrieNode{
      bool flag;
      TrieNode* child[26];
      TrieNode(){
          flag = false;
          for(int i = 0; i < 26; i++){
              child[i] = NULL;
          }
      }
    };
    
    TrieNode* head;
    WordDictionary() {
        head = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* root = head;
        for(int i = 0; i < word.size(); i++){
            if(root -> child[word[i] - 'a'] == NULL){
                root -> child[word[i] - 'a'] = new TrieNode();
            }
            root = root -> child[word[i] - 'a'];
        }
        root -> flag = true;
    }
    bool dfs(TrieNode* root, int ind, string word){
        
        if(root -> flag == true && ind == word.size()){
            return true;
        }
        
        if(ind == word.size()){
            return false;
        }
        if(word[ind] == '.'){
            for(int i = 0; i < 26; i++){
                if(root -> child[i] != NULL){
                    bool temp = dfs(root -> child[i], ind + 1, word);
                    if(temp) return true;
                }
            }
        }
        else{
            if(root -> child[word[ind] - 'a'] != NULL){
                bool temp = dfs(root -> child[word[ind] - 'a'], ind + 1, word);
                if(temp) return true;
            }
        }
        return false;
    }
    bool search(string word) {
        return dfs(head, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
