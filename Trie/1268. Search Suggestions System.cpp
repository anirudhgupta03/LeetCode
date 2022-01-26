class Solution {
public:
    struct TrieNode{
        vector<int> ind;
        TrieNode* child[26];
        TrieNode(){
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    void insert(TrieNode* root, string &s, int &index){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                root -> child[s[i] - 'a'] = new TrieNode();
            }
            root = root -> child[s[i] - 'a'];
            (root -> ind).push_back(index);
        }
    }
    vector<int> search(TrieNode* root, string &prefix){
        
        vector<int> temp;
        for(int i = 0; i < prefix.size(); i++){
            if(root -> child[prefix[i] - 'a'] == NULL){
                return temp;
            }
            root = root -> child[prefix[i] - 'a'];
        }
        return root -> ind;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        TrieNode* root = new TrieNode();
        
        sort(products.begin(), products.end());
        
        for(int i = 0; i < products.size(); i++){
            insert(root, products[i], i);
        }
        vector<int> v;
        string prefix;
        vector<vector<string>> res(searchWord.size());
        
        for(int i = 0; i < searchWord.size(); i++){
            prefix.push_back(searchWord[i]);
            v = search(root, prefix);
            for(int j = 0; j < min(3, (int)v.size()); j++){
                res[i].push_back(products[v[j]]);
            }
        }
        return res;
    }
};
