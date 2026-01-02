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
    int findMaxSum(TreeNode* root, int &maxSum){
        if(root == NULL){
            return 0;
        }
        int lt = findMaxSum(root -> left, maxSum);
        int rt = findMaxSum(root -> right, maxSum);

        int temp = max({root -> val, lt + root -> val, rt + root -> val});
        maxSum = max(maxSum, max(temp, lt + rt + root -> val));
        return max(0, temp);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMaxSum(root, maxSum);
        return maxSum;
    }
};
