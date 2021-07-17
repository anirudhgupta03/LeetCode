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
    TreeNode* solve(TreeNode* root){
        
        if(root == NULL){
            return NULL;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            return root;
        }
        
        TreeNode* ltail = solve(root -> left);
        TreeNode* rtail = solve(root -> right);
        
        if(ltail && rtail){
            ltail -> right = root -> right;
            root -> right = root ->left;
            root -> left = NULL;
        }
        else if(ltail){
            root -> right = root ->left;
            root -> left = NULL;
            return ltail;
        }
        return rtail;
    }
    void flatten(TreeNode* root) {
        
        solve(root);
    }
};
