/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        queue<TreeNode*> q1, q2;
        q1.push(original);
        q2.push(cloned);
        
        while(!q1.empty()){
            int sz = q1.size();
            while(sz--){
                TreeNode*  curr1 = q1.front();
                q1.pop();
                TreeNode* curr2 = q2.front();
                q2.pop();
                if(curr1 == target){
                    return curr2;
                }
                
                if(curr1 -> left) q1.push(curr1 -> left);
                if(curr1 -> right) q1.push(curr1 -> right);
                
                if(curr2 -> left) q2.push(curr2 -> left);
                if(curr2 -> right) q2.push(curr2 -> right);
            }
        }
        return NULL;
    }
};
