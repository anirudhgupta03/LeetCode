//Ref: https://www.youtube.com/watch?v=U7fIQ7qAeuE
class WordFilter {
public:
    struct TrieNode{
        vector<int> ind;
        TrieNode* child[26];
        TrieNode(){
            ind.clear();
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    TrieNode* root1, *root2;
    WordFilter(vector<string>& words) {
        root1 = new TrieNode();
        root2 = new TrieNode();
        
        unordered_map<string,int> umap;
        
        for(int i = 0; i < words.size(); i++){    //For repeated strings we'll take it with maximum index
            umap[words[i]] = i;
        }
        TrieNode *temp;
        
        for(auto x: umap){
            string s = x.first;
            int index = x.second;
            
            temp = root1;
            for(int j = 0; j < s.size(); j++){
                if(temp -> child[s[j] - 'a'] == NULL){
                    temp -> child[s[j] - 'a'] = new TrieNode();
                }
                temp = temp -> child[s[j] - 'a'];
                (temp -> ind).push_back(index);
            }
            
            temp = root2;
            for(int j = s.size() - 1; j >= 0; j--){
                if(temp -> child[s[j] - 'a'] == NULL){
                    temp -> child[s[j] - 'a'] = new TrieNode();
                }
                temp = temp -> child[s[j] - 'a'];
                (temp -> ind).push_back(index);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        
        TrieNode* temp = root1;
        
        for(int i = 0; i < prefix.size(); i++){
            if(temp -> child[prefix[i] - 'a'] == NULL){
                return -1;
            }
            temp = temp -> child[prefix[i] - 'a'];
        }
        
        unordered_map<int,int> mp;
        
        vector<int> v = temp -> ind;
        
        for(int i = 0; i < v.size(); i++) mp[v[i]]++;
        temp = root2;
        
        for(int i = suffix.size() - 1; i >= 0; i--){
            if(temp -> child[suffix[i] - 'a'] == NULL){
                return -1;
            }
            temp = temp -> child[suffix[i] - 'a'];
        }
      
        int ans = -1;
        v = temp -> ind;  
        sort(v.begin(),v.end());
        for(int i = v.size() - 1; i >= 0; i--){
            if(mp.find(v[i]) != mp.end()){
                return v[i];
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
