//Ref: https://www.lintcode.com/problem/448/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        
        if(root == NULL || p == NULL){
            return NULL;
        }
        if(p -> right != NULL){
            p = p -> right;
            while(p -> left){
                p = p -> left;
            }
            return p;
        }
        else{
            TreeNode* ans = NULL;
            while(root != p){
                if(root -> val > p -> val){
                    ans = root;
                    root = root -> left;
                }
                else{
                    root = root -> right;
                }
            }
            return ans;
        }
    }
};
