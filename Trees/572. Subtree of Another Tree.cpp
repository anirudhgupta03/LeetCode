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
    bool isIdentical(TreeNode* root1, TreeNode* root2){
        
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 == NULL || root1 -> val != root2 -> val){
            return false;
        }
        if(root1 -> val == root2 -> val){
            return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
        }
        return false;
    }
    void find(TreeNode* T, TreeNode* S, TreeNode* start, bool &flag){
        
        if(T == NULL){
            return;
        }
        
        if(T->val == S->val){
            start = T;
            if(isIdentical(start,S)){
                flag = true;
                return;
            }
        }
        find(T -> left, S, start,flag);
        find(T -> right, S, start,flag);
    }
    bool isSubtree(TreeNode* T, TreeNode* S) {
        TreeNode* start;
        
        bool flag = false;
        
        find(T,S,start,flag);
        
        return flag;
    }
};
