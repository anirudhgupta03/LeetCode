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
    void preorder(TreeNode* root,TreeNode* prevl, TreeNode* prevr, int target, bool &flag){
        
        if(root == NULL){
            return;
        }
        
        preorder(root->left,root,NULL,target,flag);
        
        preorder(root->right,NULL,root,target,flag);
        
        if(root -> left == NULL && root -> right == NULL && root -> val == target){
            
            if(prevl == NULL && prevr == NULL){
                root = NULL;
                flag = true;
            }
            else if(prevl != NULL){
                prevl -> left = NULL;
            }
            else if(prevr != NULL){
                prevr -> right = NULL;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool flag = false;
        preorder(root,NULL,NULL,target,flag);
        if(flag == true) return NULL;
        return root;
    }
};
