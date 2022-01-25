//Ref: https://www.lintcode.com/problem/634/?_from=collection&fromId=201
class Solution {
public:
    /**
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    struct TrieNode{
        vector<int> v;
        TrieNode* child[26];
        TrieNode(){
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    void add(TrieNode* root, string s, int ind){

        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                root -> child[s[i] - 'a'] = new TrieNode();
            }
            root = root -> child[s[i] - 'a'];
            (root -> v).push_back(ind);
        }
    }
    vector<int> search(TrieNode* root, string s){

        vector<int> temp;
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                return temp;
            }
            root = root -> child[s[i] - 'a'];
        }
        return root -> v;
    }
    void solve(TrieNode* root, string prefix, int ind, int n,  vector<string> &temp, vector<vector<string>> &res, vector<string> &words){

        if(ind == n - 1){
            vector<int> v = search(root, prefix);
            for(int i = 0; i < v.size(); i++){
                temp.push_back(words[v[i]]);
                res.push_back(temp);
                temp.pop_back();
            }
            return;
        }

        string s;
        for(int i = 0; i < temp.size(); i++){
            s += temp[i][ind + 1];
        }

        vector<int> v = search(root, prefix);

        for(int i = 0; i < v.size(); i++){
            string str = words[v[i]];
            temp.push_back(str);
            s.push_back(str[ind + 1]);
            solve(root, s, ind + 1, n, temp, res, words);
            s.pop_back();
            temp.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string> &words) {
        
        vector<vector<string>> res;

        if(words.size() == 1 && words[0].size() == 1){
            res.push_back(words);
        }

        if(words.size() == 0 || words[0].size() == 1){
            return res;
        }

        TrieNode* root = new TrieNode();

        for(int i = 0; i < words.size(); i++){
            add(root, words[i], i);
        }

        
        int n = words[0].size();

        for(int i = 0; i < words.size(); i++){
            vector<string> temp;
            temp.push_back(words[i]);
            string str;
            str.push_back(words[i][1]);
            solve(root, str, 1, n, temp, res, words);
        }
        return res;
    }
};
