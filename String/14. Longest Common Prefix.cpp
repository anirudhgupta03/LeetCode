//Method - 1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        sort(strs.begin(), strs.end());
        string res;
        int ptr = 0;
        while(ptr < strs[0].length() && ptr < strs[len - 1].length() && strs[0][ptr] == strs[len - 1][ptr]){
            res.push_back(strs[0][ptr]);
            ptr++;
        }
        return res;
    }
};

//Method - 2
struct TrieNode{
    TrieNode* child[26];
    int freq;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        freq = 0;
    }
};
class Solution {
public:
    void insertInTrie(TrieNode* root, string &s){
        for(char &ch: s){
            if(root -> child[ch - 'a'] == NULL){
                root -> child[ch - 'a'] = new TrieNode();
            }
            root = root -> child[ch - 'a'];
            root -> freq = root -> freq + 1;
        }
    }
    string searchInTrie(string &s, int len, TrieNode* root){
        string res;
        for(char &ch: s){
            root = root -> child[ch - 'a'];
            if(root == NULL || root -> freq != len){
                break;
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode();
        int len = strs.size();
        for(int i = 0; i < len; i++){
            insertInTrie(root, strs[i]);
        }
        return searchInTrie(strs[0], len, root);
    }
};
