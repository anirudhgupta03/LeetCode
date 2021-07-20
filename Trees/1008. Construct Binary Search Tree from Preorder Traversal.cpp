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
    TreeNode* buildTree(int l, int r, vector<int> &preorder){
        
        if(l > r){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[l]);
        
        int i;
        for(int j = l + 1; j <= r; j++){
            if(preorder[j] > preorder[l]){
                i = j;
                break;
            }
        }
        
        root -> left = buildTree(l+1,i-1,preorder);
        root -> right = buildTree(i,r,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int ind = 0;
        
        return buildTree(0, preorder.size() - 1, preorder);
    }
};
