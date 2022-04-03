class Encrypter {
public:
    #define ll long long
    unordered_map<string,int> dict;
    unordered_map<string,int> mp;
    unordered_map<string,int> decrypted;
    vector<string> v;
    
    struct TrieNode{
        TrieNode* child[26];
        TrieNode(){
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
    }
    bool search(TrieNode* root, string &s){
        // cout << root << endl;
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                return false;
            }
            root = root -> child[s[i] - 'a'];
        }
        return true;
    }
    
    
    TrieNode* root;
    void solve(int ind, string temp, string &s, int &count){
        if(ind == s.size()){
            // cout << temp << endl;
            if(dict[temp]){
                count++;
            }
            return;
        }
        if(!search(root, temp)){
            return;
        }
        string sub = s.substr(ind,2);
        ll t = mp[sub];
        for(ll j = 0; j < 26; j++){
            ll mask = (t & (1 << j));
            if(mask != 0){
                temp.push_back((j + 'a'));
                solve(ind + 2, temp, s, count);
                temp.pop_back();
            }
        }
    }
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        dict.clear();
        mp.clear();
        v.resize(26, "");
        for(int i = 0; i < keys.size(); i++){
            v[keys[i] - 'a'] = values[i];
            mp[values[i]] = (mp[values[i]] | (1 << (keys[i] - 'a')));
        }
        
        root = new TrieNode();
        for(string s: dictionary){
            insert(root, s);
            dict[s]++;
        }
    }
    
    string encrypt(string word1) {
        string res;
        for(int i = 0; i < word1.size(); i++){
            res += v[word1[i] - 'a'];
        }
        return res;
    }
    
    int decrypt(string word2) {
        if(decrypted[word2]){
            return decrypted[word2];
        }
        int count = 0;
        string temp;
        solve(0, temp, word2, count);
        return decrypted[word2] = count;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
