//Ref: https://www.youtube.com/watch?v=NfgCSp1ZaW0
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, int limit, int sumsofar){
        
        if(root == NULL){
            return true;
        }
        
        if(sumsofar + root -> val < limit && root -> left == NULL && root -> right == NULL){
            return true;
        }
        if(sumsofar + root -> val >= limit && root -> left == NULL && root -> right == NULL){
            return false;
        }
        bool l = false;
        bool r = false;
        
        l= dfs(root -> left, limit, sumsofar + root -> val);
        r = dfs(root -> right, limit, sumsofar + root -> val);
        
        if(l){
            root -> left = NULL;
        }
        if(r){
            root -> right = NULL;
        }
        return l && r;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        if(root == NULL){
            return NULL;
        }
        
        bool flag = dfs(root, limit, 0);
        if(flag){
            return NULL;
        }
        else{
            return root;
        }
    }
};
