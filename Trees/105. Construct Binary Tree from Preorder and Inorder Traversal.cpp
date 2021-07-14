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
    TreeNode* solve(int &ind, int l, int r, vector<int> &preorder, vector<int> &inorder){
        
        if(l > r){
            return NULL;
        }
        
        int j;
        for(int i = l; i <= r; i++){
            if(inorder[i] == preorder[ind]){
                j = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(preorder[ind]);
        ind++;
        root -> left = solve(ind,l,j-1,preorder,inorder);
        root -> right = solve(ind,j+1,r,preorder,inorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        int ind = 0;
        return solve(ind,0,n-1,preorder,inorder);
    }
};
