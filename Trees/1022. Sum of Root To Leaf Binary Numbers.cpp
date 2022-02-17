//Ref: https://www.youtube.com/watch?v=z3qqaAl-VNY
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
    int sum;
    void solve(TreeNode* root, int tsum){
        
        if(root == NULL){
            return;
        }
        
        if(root -> left == NULL && root -> right== NULL){
            sum += tsum + root -> val;
            return;
        }
        solve(root -> left, (tsum + root -> val)*2);
        solve(root -> right, (tsum + root -> val)*2);
    }
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        if(root == NULL){
            return 0;
        }
        solve(root, 0);
        return sum;
    }
};
