class Solution {
public:
    struct TrieNode{
        int freq;
        TrieNode* child[26];
        TrieNode(){
            freq = 0;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    void add(TrieNode* root, string &s){
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                root -> child[s[i] - 'a'] = new TrieNode();
            }
            root = root -> child[s[i] - 'a'];
            root -> freq++;
        }
    }
    int search(TrieNode* root, string &s){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                return 0;
            }
            root = root -> child[s[i] - 'a']; 
        }
        return root -> freq;
    }
    int prefixCount(vector<string>& words, string pref) {
        
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            add(root, words[i]);
        }
        
        return search(root, pref);
    }
};
