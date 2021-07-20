//Ref: https://www.youtube.com/watch?v=5_AZcOOc-kM
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
    int findMax(TreeNode* root){
        
        int maxVal = root -> val;
        
        while(root){
            maxVal = max(maxVal, root -> val);
            root = root -> right;
        }
        return maxVal;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL){
            return NULL;
        }
        
        if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
        }
        else if(root -> val < key){
            root -> right = deleteNode(root -> right, key);
        }
        else{
            
            if(root -> left != NULL && root -> right != NULL){
                int lmax = findMax(root -> left);
                root -> val = lmax;
                root -> left = deleteNode(root -> left, lmax);
            }
            else if(root -> left != NULL){
                return root -> left;
            }
            else if(root -> right != NULL){
                return root -> right;
            }
            else{
                return NULL;
            }
        }
        
        return root;
    }
};
