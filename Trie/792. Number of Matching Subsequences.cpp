//Using Trie
//Ref: https://leetcode.com/problems/number-of-matching-subsequences/discuss/1671120/DFS-on-the-Trie-of-the-words
class Solution {
public:
    struct TrieNode{
        bool isEnd;
        int count;  //number of same word in dict
        TrieNode* child[26];
        TrieNode(){
            isEnd = false;
            count = 0;
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
        root -> count++;
    }
    int findIndex(string &s, int &start, char c) {
        for(int i = start; i < s.size(); i++)
            if(s[i] == c) return i;
        return -1;
    }
    void dfs(int ind, TrieNode* root, string &s, int &ans){
        
        for(int i = 0; i < 26; i++){
            if(root -> child[i] != NULL){
                int idx = findIndex(s, ind, (char)(i + 'a'));
                if(idx != -1){
                    if(root -> child[i] -> isEnd) ans += root -> child[i] -> count;
                    dfs(idx + 1, root -> child[i], s, ans);
                }
            }
        }
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        
        TrieNode* root = new TrieNode();
        int ans = 0;
        
        for(int i = 0; i < words.size(); i++){
            insert(root, words[i]);
        }
        
        dfs(0, root, s, ans);
        return ans;
    }
};
