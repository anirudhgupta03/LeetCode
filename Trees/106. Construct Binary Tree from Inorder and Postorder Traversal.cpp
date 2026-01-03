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
    int ind;
    TreeNode* buildTree(int i, int j, vector<int>& inorder, vector<int>& postorder){

        if(i > j || ind == -1){
            return NULL;
        }

        int k = -1;
        for(int itr = i; itr <= j; itr++){
            if(inorder[itr] == postorder[ind]){
                k = itr;
                break;
            }
        }
        
        if(k != -1){
            TreeNode* curr = new TreeNode(postorder[ind]);
            ind--;
            curr -> right = buildTree(k + 1, j, inorder, postorder);
            curr -> left = buildTree(i, k - 1, inorder, postorder);
            return curr;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        ind = n - 1;
        return buildTree(0, n - 1, inorder, postorder);
    }
};
