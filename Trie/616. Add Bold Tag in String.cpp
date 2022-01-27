//https://www.lintcode.com/problem/add-bold-tag-in-string/description
class Solution {
public:
    /**
     * @param s: a string
     * @param dict: a list of strings
     * @return: return a string
     */
    struct TrieNode{
        unordered_map<char, TrieNode*> child;
        bool isEnd;
        TrieNode(){
            isEnd = false;
        }
    };
    void insert(TrieNode* root, string &s){
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]] == NULL){
                root -> child[s[i]] = new TrieNode();
            }
            root = root -> child[s[i]];
        }
        root -> isEnd = true;
    }
    int search(TrieNode* root, int index, string &s){
        int res = -1;
        for(int i = index; i < s.size(); i++){
            if(root -> child[s[i]] == NULL){
                if(root -> isEnd) res = i;
                break;
            }
            root = root -> child[s[i]];
            if(root -> isEnd) res = i + 1;
        }
        return res;
    }
    string addBoldTag(string &s, vector<string> &dict) {
        
        string prefix = "<b>", suffix = "</b>";

        TrieNode* root = new TrieNode();

        for(int i = 0; i < dict.size(); i++){
            insert(root, dict[i]);
        }

        string res;

        int end = -1;
        for(int i = 0; i < s.size(); i++){
            if(end >= i){
                end = max(end, search(root, i, s));
            }
            else{
                end = search(root, i, s);  
                if(end > i){
                    res += prefix;
                }
            }
            if(end == i) res += suffix;
            if(i < s.size()) res.push_back(s[i]);
        }
        if(end == s.size()) res += suffix;
        return res;
    }
};
