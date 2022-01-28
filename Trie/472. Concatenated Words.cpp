//Method - 1
//TLE
class Solution {
public:
    struct TrieNode{
        string str;
        TrieNode* child[26];
        TrieNode(){
            str = "";
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
        root -> str = s;
    }
    void search1(TrieNode* root, TrieNode* curr, unordered_set<string> &s){
        
        if(curr -> str != ""){
            search2(root, curr, root, s);
        }
        for(int i = 0; i < 26; i++){
            if(curr -> child[i] != NULL){
                search1(root, curr -> child[i], s);
            }
        }
    }
    void search2(TrieNode* root, TrieNode* curr, TrieNode* nword, unordered_set<string> &s){
        
        if(curr -> str != ""  && nword -> str != ""){
            s.insert(curr -> str);
        }
        
        if(nword -> str != ""){
            search2(root, curr, root, s);
        }
        
        for(int i = 0; i < 26; i++){
            if(curr -> child[i] != NULL && nword -> child[i] != NULL){
                search2(root, curr -> child[i], nword -> child[i], s);
            }
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        TrieNode* root = new TrieNode();
        
        for(auto &x: words){
            insert(root, x);
         }
        unordered_set<string> res;
        search1(root, root, res);
        
        for(auto &x: res){
            ans.push_back(x);
        }
        return ans;
    }
};

//Optimization
//TLE Again!!!
class Solution {
public:
    struct TrieNode{
        string str;
        TrieNode* child[26];
        TrieNode(){
            str = "";
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
        root -> str = s;
    }
    void search1(TrieNode* root, TrieNode* curr, vector<string> &s){
        
        if(curr -> str != ""){
            search2(root, curr, root, s);
        }
        for(int i = 0; i < 26; i++){
            if(curr -> child[i] != NULL){
                search1(root, curr -> child[i], s);
            }
        }
    }
    void search2(TrieNode* root, TrieNode* curr, TrieNode* nword, vector<string> &s){
        
        if(curr -> str != ""  && nword -> str != ""){
            s.push_back(curr -> str);
            curr -> str = "";
        }
        
        if(nword -> str != ""){
            search2(root, curr, root, s);
        }
        
        for(int i = 0; i < 26; i++){
            if(curr -> child[i] != NULL && nword -> child[i] != NULL){
                search2(root, curr -> child[i], nword -> child[i], s);
            }
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        TrieNode* root = new TrieNode();
        
        for(auto &x: words){
            insert(root, x);
        }
        
        search1(root, root, res);
        
        return res;
    }
};

//Optimization
//TLE Again!!!
class Solution {
public:
    struct TrieNode{
        string str;
        bool added;
        TrieNode* child[26];
        TrieNode(){
            str = "";
            added = false;
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
        root -> str = s;
    }
    void search1(TrieNode* &root, TrieNode* curr, vector<string> &s){
        
        if(curr -> str != ""){
            search2(root, curr, root, s);
        }
        for(int i = 0; i < 26; i++){
            if(curr -> child[i] != NULL){
                search1(root, curr -> child[i], s);
            }
        }
    }
    void search2(TrieNode* &root, TrieNode* curr, TrieNode* nword, vector<string> &s){
        
        if(curr -> str != ""  && nword -> str != ""){
            if(curr -> added == false){
                s.push_back(curr -> str);
                curr -> added = true;
            }
        }
        else if(nword -> str != ""){
            search2(root, curr, root, s);
        }
        
        for(int i = 0; i < 26; i++){
            if(curr -> child[i] && nword -> child[i]){
                search2(root, curr -> child[i], nword -> child[i], s);
            }
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        vector<string> res;
        TrieNode* root = new TrieNode();
        
        for(auto &x: words){
            insert(root, x);
        }
        
        search1(root, root, res);
        
        return res;
    }
};
