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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL){
            TreeNode* curr = new TreeNode(val);
            return curr;
        }
        
        TreeNode* temp = root, *prev = root;
        while(temp){
            if(temp -> val > val){
                prev = temp;
                temp = temp -> left;
                if(!temp){
                    TreeNode* curr = new TreeNode(val);
                    prev -> left = curr;
                    break;
                }
            }
            else{
                prev = temp;
                temp = temp -> right;
                if(!temp){
                    TreeNode* curr = new TreeNode(val);
                    prev -> right = curr;
                    break;
                }
            }
        }
        return root;
    }
};
