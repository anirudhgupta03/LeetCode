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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0, val;
        while(!q.empty()){
            int sz = q.size();
            if(level % 2 == 0) val = INT_MIN;
            else               val = INT_MAX;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                
                int curr = node -> val;
                
                if(level % 2 == 0 && curr % 2 == 0 || level % 2 != 0 && curr % 2 != 0){
                    return false;
                }
                if(level % 2 != 0){
                    if(curr >= val){
                        return false;
                    }
                    else{
                        val = curr;
                    }
                }
                else{
                    if(curr <= val){
                        return false;
                    }
                    else{
                        val = curr;
                    }
                }
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            level++;
        }
        return true;
    }
};
