//Ref: https://www.youtube.com/watch?v=kTL5LhCTL1c
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
    vector<int> houseRobber(TreeNode* root){
        
        if(root == NULL){
            vector<int> temp = {0,0};
            return temp;
        }
        
        vector<int> left = houseRobber(root -> left);
        vector<int> right = houseRobber(root -> right);
        
        vector<int> res(2);
        
        res[0] = left[1] + root -> val + right[1];
        res[1] = max(left[0],left[1]) + max(right[0],right[1]);
        
        return res;
    }
    int rob(TreeNode* root) {
        
          vector<int> ans = houseRobber(root);
          return max(ans[0],ans[1]);
    }
};
