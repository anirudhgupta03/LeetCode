class Solution {
public:
    struct TrieNode{
        bool end;
        TrieNode* child[26];
        TrieNode(){
            end = false;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    void insert(TrieNode* root, string s){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                root -> child[s[i] - 'a'] = new TrieNode();
            }
            root = root -> child[s[i] - 'a'];
        }
        root -> end = true;
    }
    string search(TrieNode* root, string s){
        
        if(root -> child[s[0] - 'a'] == NULL){
            return s;
        }
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                if(root -> end){
                    return s.substr(0, i);
                }
                else{
                    return s;
                }
            }
            root = root -> child[s[i] - 'a'];
            if(root -> end){
                return s.substr(0, i + 1);
            }
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < dictionary.size(); i++){
            insert(root, dictionary[i]);
        }
        
        stringstream X(sentence);
        string temp;
        
        string res;
        while(X >> temp){
            string ans = search(root, temp);
            res += ans;
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};
