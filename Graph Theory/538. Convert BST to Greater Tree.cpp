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
    void inorder(TreeNode* root, vector<int> &v){
        
        if(root == NULL){
            return;
        }
        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }
    void solve(int &ind, vector<int> &v, TreeNode* root){
        
        if(root == NULL){
            return;
        }
        solve(ind, v, root -> left);
        root -> val = v[ind];
        ind++;
        solve(ind, v, root -> right);
    }
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL){
            return NULL;
        }
        
        vector<int> v;
        inorder(root, v);
        
        for(int i = v.size() - 2; i >= 0; i--){
            v[i] += v[i + 1];
        }
        
        int ind = 0;
        solve(ind, v, root);
        return root;
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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL){
            return NULL;
        }
        
        convertBST(root -> right);
        sum += root -> val;
        root -> val = sum;
        convertBST(root -> left);
        return root;
    }
};
