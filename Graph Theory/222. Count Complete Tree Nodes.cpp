//Ref: https://www.youtube.com/watch?v=u-yWemKGWO0
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
    int findHeightLeft(TreeNode* node){
        int height = 0;
        while(node){
            node = node -> left;
            height++;
        }
        return height;
    }
    int findHeightRight(TreeNode* node){
        int height = 0;
        while(node){
            node = node -> right;
            height++;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        
        if(lh == rh){
            return pow(2, lh) - 1;
        }
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
