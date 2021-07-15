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
    void solve(TreeNode* root, int &k, int &ele){
        
        if(root == NULL){
            return;
        }
        
        solve(root -> left, k, ele);
        
        k--;
        if(k == 0){
            ele = root -> val;
            return;
        }
        
        solve(root -> right, k, ele);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int ele;
        solve(root,k,ele);
        
        return ele;
    }
};
