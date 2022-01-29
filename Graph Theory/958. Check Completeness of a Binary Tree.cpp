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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int h = 0;
        while(!q.empty()){
            int sz = q.size();
            bool flag = true;
            
            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr -> left == NULL){
                    flag = false;
                }
                else{
                    if(flag){
                        q.push(curr -> left);
                    }
                    else{
                        return false;
                    }
                }
              
                if(curr -> right == NULL){
                    flag = false;
                }
                else if(curr -> right == NULL){
                     if(flag){
                        q.push(curr -> right);
                    }
                    else{
                        return false;
                    }
                }
            }
            if(!q.empty() && sz != pow(2, h)){
                return false;
            }
            h++;
        }
        return true;
    }
};
