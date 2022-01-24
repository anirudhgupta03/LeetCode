//Ref: https://www.youtube.com/watch?v=UQzXYDN49cs
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
    void helper(TreeNode* root, int sum, int &ans){
        if(root == NULL) return;
        if(sum == root -> val) ans++;
        sum = sum - root -> val;
        helper(root -> left, sum, ans);
        helper(root -> right, sum, ans);
    }
    void solve(TreeNode* root, int sum, int &ans){
        if(root == NULL){
            return;
        }
        helper(root, sum, ans);
        solve(root -> left, sum, ans);
        solve(root -> right, sum, ans);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        int ans = 0;
        solve(root, sum, ans);
        return ans;
    }
};
