//Method - 1
//https://www.lintcode.com/problem/binary-tree-upside-down/description
//https://www.codingninjas.com/codestudio/problems/upside-down-binary-tree_1281853?leftPanelTab=0
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode* solve(TreeNode * root, bool &flag, TreeNode* &start){

        if(root == NULL){
            return NULL;
        }

        if(root -> left == NULL && root -> right == NULL){
            return root;
        }

        TreeNode* lefttree = solve(root -> left, flag,start);
        TreeNode* righttree = root -> right;

        if(!flag){
            flag = true;
            start = lefttree;
        }
        root -> left = NULL;
        root -> right = NULL;

        lefttree -> left = righttree;
        lefttree -> right = root;
        return root;
    }
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        
        if(root == NULL){
            return NULL;
        }
        bool flag = false;
        TreeNode* start = root;
        solve(root, flag, start);

        return start;
    }
};

//Method - 2
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode* upsideDownBinaryTree(TreeNode *root) {
        
        if(root == NULL) return root;
        stack<TreeNode*> st;
        TreeNode* head = NULL;

        while(root){
            st.push(root);
            root = root -> left;
        }
         
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(head == NULL){
                head = curr;
            }

            if(!st.empty()){
                TreeNode* par = st.top();
                TreeNode* rt = par -> right;
                curr -> left = rt;
                par -> left = NULL;
                par -> right = NULL;
                curr -> right = par;
            }
        }
        return head;
    }
};
