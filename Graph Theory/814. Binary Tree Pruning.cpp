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
    bool solve(TreeNode* root){
        
        if(root == NULL){
            return true;
        }
        
        bool flag1 = solve(root -> left);
        bool flag2 = solve(root -> right);
        
        if(flag1){
            root -> left = NULL;
        }
        if(flag2){
            root -> right = NULL;
        }
        if(root -> val == 0 && flag1 && flag2){
            return true;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root == NULL){
            return NULL;
        }
        bool flag = solve(root);
        if(flag){
            return NULL;
        }
        return root;
    }
};
