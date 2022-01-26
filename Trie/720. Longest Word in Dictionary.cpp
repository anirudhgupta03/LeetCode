//Same Question: 1858. Longest Word With All Prefixes
//Method - 1
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
    string longestWord(vector<string>& words) {
        
        sort(words.begin(),words.end());
        
        for(int i = 0; i < words.size(); i++){
            cout << words[i] << " ";
        }
        cout << endl;
        
        TrieNode* node = new TrieNode();
        
        string ans;
        int length = 0;
        
        for(int i = 0; i < words.size(); i++){
            bool flag = true;
            TrieNode* temp = node;
            int sz = words[i].size() - 1;
            for(int j = 0; j < words[i].size() - 1; j++){
                if(temp -> child[words[i][j] - 'a'] == NULL){
                    flag = false;
                    temp -> child[words[i][j] - 'a'] = new TrieNode();
                }
                if(temp -> child[words[i][j] - 'a'] -> end == false){
                    flag = false;
                }
                temp = temp -> child[words[i][j] -'a'];
            }
            if(flag){
                cout << words[i] << endl;
                if(words[i].size() > length){
                    length = words[i].size();
                    ans = words[i];
                }
                else if(words[i].size() == length){
                    if(words[i] < ans){
                        ans = words[i];
                    }
                }
            }
            if(temp -> child[words[i][words[i].size() - 1] - 'a'] == NULL){
                temp -> child[words[i][words[i].size() - 1] - 'a'] = new TrieNode();
            }
            temp = temp -> child[words[i][words[i].size() - 1] - 'a'];
            temp -> end = true;
        }
        
        return ans;
    }
};

//Alter
class Solution {
public:
    struct TrieNode{
        bool isEnd;
        TrieNode* child[26];
        
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    bool static cmp(string &s1, string &s2){
        if(s1.size() == s2.size()){
            return s1 < s2;
        }
        return s1.size() < s2.size();
    }
    bool helper(TrieNode* root, string &s){
        
        int n = s.size();
        bool flag = true;
        for(int i = 0; i < s.size() - 1; i++){
            if(root -> child[s[i] - 'a'] == NULL){
                flag = false;
                root -> child[s[i] - 'a'] = new TrieNode();
            }
            root = root -> child[s[i] - 'a'];
            if(!(root -> isEnd)){
                flag = false;
            }
        }
        if(root -> child[s[n - 1] - 'a'] == NULL){
            root -> child[s[n - 1] - 'a'] = new TrieNode();
        }
        root = root -> child[s[n - 1] - 'a'];
        root -> isEnd = true;
        return flag;
    }
    string longestWord(vector<string>& words) {
        
        TrieNode* root = new TrieNode();
        
        sort(words.begin(), words.end(), cmp);
        
        int maxlen = 0;
        string res;
        for(int i = 0; i < words.size(); i++){
            if(helper(root, words[i])){
                if(maxlen < words[i].size()){
                    maxlen = words[i].size();
                    res = words[i];
                }
                else if(maxlen == words[i].size()){
                    if(words[i] < res){
                        res = words[i];
                    }
                }
            }
        }
        return res;
    }
};
