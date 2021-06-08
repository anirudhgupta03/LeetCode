//Using Trie
class Solution {
public:
    struct TrieNode{
    
        int val;
        TrieNode* left;
        TrieNode* right;

        TrieNode(){
            val = 0;
            left = NULL;
            right = NULL;
        }
    };

    void add(TrieNode* root, int n){

        for(int i = 31; i >= 0; i--){

            if((n & (1 << i)) != 0){
                if(root -> right == NULL){
                    root -> right = new TrieNode();
                }
                root = root -> right;
            }
            else{
                if(root -> left == NULL){
                    root -> left = new TrieNode();
                }
                root = root -> left;
            }
        }
        root -> val = n;
    }

    int findMaxXOR(TrieNode* root, int n){

        for(int i = 31; i >= 0; i--){

            if((n & (1 << i)) != 0){

                if(root -> left != NULL){
                    root = root -> left;
                }
                else{
                    root = root -> right;
                }
            }
            else{

                if(root -> right != NULL){
                    root = root -> right;
                }
                else{
                    root = root -> left;
                }
            }
        }
        return (n ^ (root -> val));
    }
    int findMaximumXOR(vector<int>& A) {

        TrieNode* root = new TrieNode();
    
        add(root,A[0]);

        int max_xor = 0;

        for(int i = 1; i < A.size(); i++){

            max_xor = max(max_xor, findMaxXOR(root,A[i]));

            add(root,A[i]);
        }
        return max_xor;
    }
};
