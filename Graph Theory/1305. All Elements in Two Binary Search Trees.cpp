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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        stack<TreeNode*> st1, st2;
        
        TreeNode* temp = root1;
        
        while(temp){
            st1.push(temp);
            temp = temp -> left;
        }
        
        temp = root2;
        
        while(temp){
            st2.push(temp);
            temp = temp -> left;
        }
        
        vector<int> res;
        while(!st1.empty() && !st2.empty()){
            TreeNode* curr1 = st1.top(), *curr2 = st2.top();
            st1.pop();
            st2.pop();
            
            int minele = min(curr1 -> val, curr2 -> val);
            
            if(minele == curr1 -> val){
                res.push_back(minele);
                curr1 = curr1 -> right;
                while(curr1){
                    st1.push(curr1);
                    curr1 = curr1 -> left;
                }
            }
            else{
                st1.push(curr1);
            }
            if(minele == curr2 -> val){
                res.push_back(minele);
                curr2 = curr2 -> right;
                while(curr2){
                    st2.push(curr2);
                    curr2 = curr2 -> left;
                }
            }
            else{
                st2.push(curr2);
            }
        }
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            res.push_back(curr -> val);
            curr = curr -> right;
            while(curr){
                st1.push(curr);
                curr = curr -> left;
            }
        }
        while(!st2.empty()){
            TreeNode* curr = st2.top();
            st2.pop();
            res.push_back(curr -> val);
            curr = curr -> right;
            while(curr){
                st2.push(curr);
                curr = curr -> left;
            }
        }
        return res;
    }
};
