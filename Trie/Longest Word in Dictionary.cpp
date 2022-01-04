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
