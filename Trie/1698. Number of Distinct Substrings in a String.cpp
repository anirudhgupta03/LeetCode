//https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?leftPanelTab=0
/*You are required to complete this method */
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
int helper(TrieNode* root, string &s){
    
    for(int i = 0; i < s.size(); i++){
        if(root -> child[s[i] - 'a'] == NULL){
            root -> child[s[i] - 'a'] = new TrieNode();
        }
        root = root -> child[s[i] - 'a'];
    }
    if(root -> isEnd){
        return 0;
    }
    root -> isEnd = true;
    return 1;
}
int countDistinctSubstrings(string &s)
{
    if(s.size() == 0){
        return 1;
    }
    TrieNode* root = new TrieNode();
    int count = 1;
    for(int i = 0; i < s.size(); i++){
        string str;
        for(int j = i; j < s.size(); j++){
            str.push_back(s[j]);
            count += helper(root, str);
        }
    }
    return count;
}
