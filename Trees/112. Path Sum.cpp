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
    bool solve(TreeNode* root, int sum, int targetSum){
        
        if(root == NULL){
            return false;
        }
        if(root -> left == NULL && root -> right == NULL){
            if(sum + root -> val == targetSum){
                return true;
            }
            else{
                return false;
            }
        }
        bool flag = solve(root -> left, sum + root -> val, targetSum);
        if(flag) return true;
        flag = solve(root -> right, sum + root -> val, targetSum);
        if(flag) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, 0, targetSum);
    }
};
