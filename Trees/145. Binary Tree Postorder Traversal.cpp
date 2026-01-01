//Method - 1
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        if(root == NULL){
            return res;
        }
        
        stack<TreeNode*> st1, st2;
        st1.push(root);
        
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);
            
            if(curr -> left) st1.push(curr -> left);
            if(curr -> right) st1.push(curr -> right);            
        }
        while(!st2.empty()){
            TreeNode* curr = st2.top();
            res.push_back(curr -> val);
            st2.pop();
        }
        return res;
    }
};

//Method - 2
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st;

        while(root){
            st.push(root);
            root = root -> left;
        }

        while(!st.empty()){
            TreeNode* curr = st.top();
            if(curr -> right == NULL){
                st.pop();
                postorder.push_back(curr -> val);
                while(!st.empty() && curr == st.top() -> right){
                    curr = st.top();
                    st.pop();
                    postorder.push_back(curr -> val);
                }
            }
            else{
                curr = curr -> right;
                while(curr){
                    st.push(curr);
                    curr = curr -> left;
                }
            }
        }
        return postorder;
    }
};
