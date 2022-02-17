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
    bool isCousins(TreeNode* root, int x, int y) {
        
        TreeNode* par1, *par2;
        int depth1, depth2;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int depth = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr -> left){
                    if(curr -> left -> val == x){
                        par1 = curr;
                        depth1 = depth;
                    }
                    else if(curr -> left -> val == y){
                        par2 = curr;
                        depth2 = depth;
                    }
                    q.push(curr -> left);
                }
                if(curr -> right){
                    if(curr -> right -> val == x){
                        par1 = curr;
                        depth1 = depth;
                    }
                    else if(curr -> right -> val == y){
                        par2 = curr;
                        depth2 = depth;
                    }
                    q.push(curr -> right);
                }
            }
            depth++;
        }
        if(par1 != par2 && depth1 == depth2){
            return true;
        }
        return false;
    }
};
