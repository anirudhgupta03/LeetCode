// In the worst case query qq has length mm and it is equal to all nn strings of the array.
// Time complexity : preprocessing O(S)O(S), where SS is the number of all characters in the array, LCP query O(m)O(m).
// Trie build has O(S)O(S) time complexity. To find the common prefix of qq in the Trie takes in the worst case O(m)O(m).
// Space complexity : O(S)O(S). We only used additional SS extra space for the Trie.

class Solution {
public:
    struct TrieNode{
        int pc;
        TrieNode* child[26];

        TrieNode(){
            pc = 0;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };

    void add(string s, TrieNode* root, int idx){

        if(idx == s.size()){
            return;
        }

        if(root -> child[s[idx]-'a'] == NULL){
            root->child[s[idx]-'a'] = new TrieNode();
        }

        root->child[s[idx]-'a']->pc++;
        add(s,root->child[s[idx]-'a'],idx+1);
    }

    int findLCP(TrieNode* root, string s, int idx, int n){

        if(idx == s.size() || root->child[s[idx]-'a']->pc < n){
                return idx;
        }

        if(root->child[s[idx]-'a'] != NULL){
                return findLCP(root->child[s[idx]-'a'],s,idx+1,n);
        }
        return 0;
    }
    string longestCommonPrefix(vector<string>& A) {

            int n = A.size();

            if(n == 1){
                return A[0];
            }
            TrieNode* root = new TrieNode();

            for(int i = 0; i < A.size(); i++){
                add(A[i],root,0);
            }
            int ans = 0;
            return A[0].substr(0,findLCP(root,A[0],0,n));
    }
};
