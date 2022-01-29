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
    bool findTarget(TreeNode* root, int k) {
        
        if(root == NULL){
            return false;
        }
        stack<TreeNode*> st1, st2;
        
        TreeNode* temp = root;
        st1.push(temp);
        temp = temp -> left;
        while(temp){
            st1.push(temp);
            temp = temp -> left;
        }
      
        temp = root;
        st2.push(root);
        temp = root -> right;
        while(temp){
            st2.push(temp);
            temp = temp -> right;
        }
        
        while(!st1.empty() && !st2.empty()){
            TreeNode* l = st1.top();
            TreeNode* r = st2.top();
            int lval = l -> val, rval = r -> val;
            
            if(lval > rval){
                break;
            }
            
            if(lval + rval == k && l != r){
                return true;
            }
            else if(lval + rval < k){
                st1.pop();
                l = l -> right;
                while(l){
                    st1.push(l);
                    l = l -> left;
                }
            }
            else{
                st2.pop();
                r = r -> left;
                while(r){
                    st2.push(r);
                    r = r -> right;
                }
            }
        }
        return false;
    }
};
