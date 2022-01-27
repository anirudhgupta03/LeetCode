class Solution {
public:
    struct TrieNode{
        vector<int> index;
        TrieNode* child[26];
        TrieNode(){
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    void insert(TrieNode* root, string &s, int &ind){
        
        vector<int> alpha(26, 0);
        
        for(int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(alpha[i] == 0) continue;
            if(root -> child[i] == NULL){
                root -> child[i] = new TrieNode();
            }
            root = root -> child[i];
        }
        (root -> index).push_back(ind);
    }
    void dfs(TrieNode* root, char &firstchar, int &count, bool &flag, vector<int> &alpha, vector<string> &words){
        
        if((root -> index).size() != 0){
            if(flag){
                count += (root -> index).size();
            }   
        }
        for(int i = 0; i < 26; i++){
            if(root -> child[i] != NULL){
                if(alpha[i]){
                    if(firstchar - 'a' == i && !flag){
                        flag = true;
                        dfs(root -> child[i], firstchar, count, flag, alpha, words);
                        flag = false;
                    }
                    else{
                        dfs(root -> child[i], firstchar, count, flag, alpha, words);
                    }
                }
            }
        }
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < words.size(); i++){
            insert(root, words[i], i);
        }
        
        vector<int> res;
        for(int i = 0; i < puzzles.size(); i++){
            vector<int> alpha(26, 0);
            for(int j = 0; j < puzzles[i].size(); j++){
                alpha[puzzles[i][j] - 'a']++;
            }
            int count = 0;
            bool flag = false;
            dfs(root, puzzles[i][0], count, flag, alpha, words);
            res.push_back(count);
        }
        return res;
    }
};
