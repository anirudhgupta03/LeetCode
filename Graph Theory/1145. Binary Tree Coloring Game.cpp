//Ref: https://www.youtube.com/watch?v=_oFVfRvyplc
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
    int lc, rc;
    int count(TreeNode* root, int x){
        
        if(root == NULL){
            return 0;
        }
        int left = count(root -> left, x);
        int right = count(root -> right, x);
        
        if(root -> val == x){
            lc = left;
            rc = right;
        }
        
        return left + right + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        lc = rc = 0;
        count(root, x);
        int nnpex = n - (lc + rc + 1);
        int maxcount = max({nnpex, lc, rc});
        if(maxcount > n/2){
            return true;
        }
        return false;
    }
};
