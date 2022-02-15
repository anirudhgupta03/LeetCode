//Ref: https://www.youtube.com/watch?v=xe6cLIhberQ
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int psi, int pei, int ppsi, int ppei){
        
        if(psi > pei){
            return NULL;
        }
        TreeNode* root = new TreeNode();
        root -> val = preorder[psi];
        
        if(psi == pei){
            return root;
        }
        int idx = ppsi;
        while(postorder[idx] != preorder[psi + 1]){
            idx++;
        }
        
        int tnel = idx - ppsi + 1;
        
        root -> left = buildTree(preorder, postorder, psi + 1, psi + tnel, ppsi, idx);
        root -> right = buildTree(preorder, postorder, psi + tnel + 1, pei, idx + 1, ppei);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return buildTree(preorder, postorder, 0, n - 1, 0, n - 1);
    }
};
