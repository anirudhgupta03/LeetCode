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
    void dfs(TreeNode* root, int &maxValue, int &count){
     
        if(root == NULL){
            return;
        }
        
        int temp = maxValue;
        maxValue = max(maxValue, root -> val);
        if(root -> val == maxValue){
            count++;
        }
        dfs(root -> left, maxValue, count);
        dfs(root -> right, maxValue, count);
        maxValue = temp;
    }
    int goodNodes(TreeNode* root) {
        
        int count = 0;
        int maxValue = INT_MIN;
        
        dfs(root, maxValue, count);
        return count;
    }
};
