class Solution {
public:
    int dx[8] = {1,-1,0,0};
    int dy[8] = {0,0,1,-1};
    
    struct TrieNode{
      TrieNode* child[26];
      string word;
      bool wordend;
      
      TrieNode(){
          for(int i = 0; i < 26; i++){
              child[i] = NULL;
          }
          word = "";
          wordend = false;
      }
    };
    void add(TrieNode* root, string s){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i]-'a'] == NULL){
                root -> child[s[i]-'a'] = new TrieNode();
            }
            root = root -> child[s[i]-'a'];
        }
        root -> word = s;
        root -> wordend = true;
    }
    void find(int i, int j, char ch, TrieNode* root, vector<vector<char>> &board, vector<vector<int>> &vis, set<string> &s){
        
        root = root -> child[ch -'a'];
        
        if(root == NULL){
            return;
        }
        
        if(root -> wordend == true){
            s.insert(root->word);
        }
        
        vis[i][j] = 1;
        
        for(int k = 0; k < 4; k++){
            
            int io = i + dx[k], jo = j + dy[k];
            
            if(io >= 0 && io < board.size() && jo >= 0 && jo < board[0].size() && vis[io][jo] == 0) {
                
                char c = board[io][jo];
                
                find(io,jo,c,root,board,vis,s);
            }
        }
        
        vis[i][j] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& dictionary) {
        
        int m = board.size(), n = board[0].size();
	    
	    TrieNode* root = new TrieNode();
	    
	    for(int i = 0; i < dictionary.size(); i++){
	        add(root,dictionary[i]);
	    }
	    
	    set<string> s;
	    
	    vector<string> res;
	    
	    for(int i = 0; i < m; i++){
	        for(int j = 0; j < n; j++){
	            
	            if(root -> child[board[i][j]-'a'] != NULL){
	                
	                vector<vector<int>> vis(m,vector<int>(n,0));
	                
	                find(i,j,board[i][j],root,board,vis,s);
	            }
	        }
	    }
	    
	    for(auto x: s){
	        res.push_back(x);
	    }
	    return res;
    }
};
