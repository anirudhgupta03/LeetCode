//https://www.lintcode.com/problem/binary-tree-upside-down/description
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode* solve(TreeNode * root, bool &flag, TreeNode* &start){

        if(root == NULL){
            return NULL;
        }

        if(root -> left == NULL && root -> right == NULL){
            return root;
        }

        TreeNode* lefttree = solve(root -> left, flag,start);
        TreeNode* righttree = root -> right;

        if(!flag){
            flag = true;
            start = lefttree;
        }
        root -> left = NULL;
        root -> right = NULL;

        lefttree -> left = righttree;
        lefttree -> right = root;
        return root;
    }
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        
        if(root == NULL){
            return NULL;
        }
        bool flag = false;
        TreeNode* start = root;
        solve(root, flag, start);

        return start;
    }
};
