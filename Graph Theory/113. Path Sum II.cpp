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
    void solve(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res, int &targetSum){
        
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            if(sum + root -> val == targetSum){
                path.push_back(root -> val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        path.push_back(root -> val);
        solve(root -> left, sum + root -> val, path, res, targetSum);
        solve(root -> right, sum + root -> val, path, res, targetSum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        
        if(root == NULL){
            return res;
        }
        
        vector<int> path;
        
        int sum = 0;
        
        solve(root, sum, path, res, targetSum);
        
        return res;
    }
};
