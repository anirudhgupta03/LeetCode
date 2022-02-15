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
    void solve(TreeNode* root, int depth, int &mindepth){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            mindepth = min(mindepth, depth);
        }
        solve(root -> left, depth + 1, mindepth);
        solve(root -> right, depth + 1, mindepth);
    }
    int minDepth(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int mindepth = INT_MAX, depth = 0;
        solve(root, depth, mindepth);
        return mindepth + 1;
    }
};
