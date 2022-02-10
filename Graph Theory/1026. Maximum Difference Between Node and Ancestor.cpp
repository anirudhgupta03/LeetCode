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
    void solve(TreeNode* root, int &maxDiff, int minVal, int maxVal){
        
        if(root == NULL){
            return;
        }
        
        minVal = min(minVal, root -> val);
        maxVal = max(maxVal, root -> val);
        
        maxDiff = max(maxDiff, maxVal - minVal);
        
        solve(root -> left, maxDiff, minVal, maxVal);
        solve(root -> right, maxDiff, minVal, maxVal);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int maxDiff = 0;
        
        solve(root, maxDiff, INT_MAX, INT_MIN);
        
        return maxDiff;
    }
};
