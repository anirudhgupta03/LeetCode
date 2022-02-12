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
    vector<int> v;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root -> left);
        v.push_back(root -> val);
        inorder(root -> right);
    }
    TreeNode* buildTree(vector<int> &v, int lo, int hi){
        if(lo > hi){
            return NULL;
        }
        
        int mid = (lo + hi)/2;
        TreeNode* curr = new TreeNode();
        curr -> val = v[mid];
        curr -> left = buildTree(v, lo, mid - 1);
        curr -> right = buildTree(v, mid + 1, hi);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        v.clear();
        inorder(root);
        return buildTree(v, 0, v.size() - 1);
    }
};
