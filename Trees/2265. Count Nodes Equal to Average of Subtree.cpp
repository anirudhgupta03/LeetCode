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
    #define pii pair<int,int>
    int count;
    pii solve(TreeNode* root){
        
        if(root == NULL){
            return {0,0};
        }
        
        pii l = solve(root -> left);
        pii r = solve(root -> right);
        
        if((root -> val + l.second + r.second)/(1 + l.first + r.first) == root -> val){
            count++;
        }
        
        return {1 + l.first + r.first, root -> val + l.second + r.second};
    }
    int averageOfSubtree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        if(root -> left == NULL && root -> right == NULL){
            return 1;
        }
        count = 0;
        
        solve(root);
        
        return count;
    }
};
