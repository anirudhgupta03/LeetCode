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
    int count;
    void solve(TreeNode* root, int maxVal){
        
        if(root == NULL) return;
        if(maxVal <= root -> val){
            count++;
        }
        solve(root -> left, max(maxVal, root -> val));
        solve(root -> right, max(maxVal, root -> val));
    }
    int goodNodes(TreeNode* root) {
        count = 0;
        solve(root, INT_MIN);
        return count;
    }
};
