//Recursive
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
    void solve(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        solve(root -> left, inorder);
        inorder.push_back(root -> val);
        solve(root -> right, inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        solve(root, inorder);
        return inorder;
    }
};

//Iterative
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        while(root){
            st.push(root);
            root = root -> left;
        }

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            inorder.push_back(curr -> val);
            if(curr -> right){
                curr = curr -> right;
                while(curr){
                    st.push(curr);
                    curr = curr -> left;
                }
            }
        }
        return inorder;
    }
};
