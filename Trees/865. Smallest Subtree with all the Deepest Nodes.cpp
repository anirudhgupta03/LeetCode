//Ref: https://www.youtube.com/watch?v=uod_6_NNWrk
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
    int postOrder(TreeNode* &root, TreeNode* &result, int &maxDepth, int depth){
        
        if(root == NULL){
            return depth;
        }
        int l = postOrder(root -> left, result, maxDepth, depth + 1);
        int r = postOrder(root -> right, result, maxDepth, depth + 1);
        
        if(l == r){
            maxDepth = max(maxDepth, l);
            if(maxDepth == l){
                result = root;
            }
        }
        return max(l, r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        int maxDepth = -1;
        TreeNode* result;
        
        postOrder(root, result, maxDepth, 0);
        return result;
    }
};
