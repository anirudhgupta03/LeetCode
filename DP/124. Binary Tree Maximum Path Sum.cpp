//Method - 1
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
    int maxSum;
    int solve(TreeNode* root){
        
        if(root == NULL){
            return INT_MIN;
        }
        
        int lval = solve(root -> left);
        int rval = solve(root -> right);
        
        int temp;
        if(lval != INT_MIN && rval != INT_MIN){
            temp = max({lval + root -> val, rval + root -> val, root -> val});
            maxSum = max({maxSum, temp, lval, rval, lval + rval + root -> val});
        }
        else if(lval != INT_MIN){
            temp = max({lval + root -> val, root -> val});
            maxSum = max({maxSum, temp, lval});
        }
        else if(rval != INT_MIN){
            temp = max({rval + root -> val, root -> val});
            maxSum = max({maxSum, temp, rval});
        }
        else{
            temp = root -> val;
            maxSum = max(maxSum, temp);
        }
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};

//Method - 2
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
    int solve(TreeNode* root, int& res){
        
        if(root == NULL){
            return 0;
        }
        
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        int temp = max(max(l,r)+ root->val, root->val);
        int ans =  max(temp, l+r+root->val);
        res = max(res,ans);
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};
