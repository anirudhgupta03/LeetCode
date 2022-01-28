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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            TreeNode* temp = new TreeNode();
            temp -> val = val;
            temp -> left = root;
            return temp;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            depth--;
            
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                
                TreeNode* l = curr -> left;
                TreeNode* r = curr -> right;
                
                if(depth == 1){
                    TreeNode* temp1 = new TreeNode();
                    temp1 -> val = val;
                    curr -> left = temp1;
                    temp1 -> left = l;
                   
                    TreeNode* temp2 = new TreeNode();
                    temp2 -> val = val;
                    curr -> right = temp2;
                    temp2 -> right = r;
                }
                else{
                    if(l) q.push(l);
                    if(r) q.push(r);
                }
            }
            if(depth == 1){
                break;
            }
        }
        return root;
    }
};
