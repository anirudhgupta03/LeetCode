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
    void solve(TreeNode* root, int sum, int &totalSum){
        
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            totalSum += 10*sum + root -> val;
            return;
        }
        
        solve(root -> left, 10*sum + root -> val, totalSum);
        solve(root -> right, 10*sum + root -> val, totalSum);
    }
    int sumNumbers(TreeNode* root) {
        
        int sum = 0, totalSum = 0;
        
        solve(root, sum, totalSum);
        
        return totalSum;
    }
};
