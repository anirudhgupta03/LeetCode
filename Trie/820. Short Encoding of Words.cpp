//Ref: https://www.youtube.com/watch?v=iRapI0M7viQ
//Method - 1
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        unordered_set<string> us;
        
        for(int i = 0; i < words.size(); i++){
            us.insert(words[i]);
        }
        
        for(int i = 0; i < words.size(); i++){
            for(int j = 1; j < words[i].size(); j++){
                us.erase(words[i].substr(j));
            }
        }
        
        int length = 0;
        for(auto x: us){
            length += x.size();
            length++;
        }
        return length;
    }
};

//Method - 2
//Using Trie
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
    void insert(TrieNode* root, string key){
        
        for(int i = 0; i < key.size() - 1; i++){
            if(root -> child[key[i] - 'a'] == NULL){
                root -> child[key[i] - 'a'] = new TrieNode();
            }
            root = root -> child[key[i] - 'a'];
            if(root -> end) root -> end = false;
        }
        if(root -> child[key[key.size() - 1] - 'a'] == NULL){
            root -> child[key[key.size() - 1] - 'a'] = new TrieNode();
            root = root -> child[key[key.size() - 1] - 'a'];
            root -> end = true;
        }
    }
    void dfs(TrieNode* root, int &ans, int count){
        
        if(root -> end){
            ans += count;
            ans++;
            return;
        }
        for(int i = 0; i < 26; i++){
            if(root -> child[i]){
                dfs(root -> child[i], ans, count + 1);
            }
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < words.size(); i++){
            string key = words[i];
            reverse(key.begin(),key.end());
            insert(root, key);
        }
        int ans = 0, count = 0;
        dfs(root, ans, count);
        return ans;
    }
};
