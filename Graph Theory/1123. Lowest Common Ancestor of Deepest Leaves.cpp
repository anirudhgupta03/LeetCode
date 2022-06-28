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
    int solve(TreeNode* root, TreeNode* &result, int &maxDepth, int depth){
        
        if(root == NULL){
            return depth;
        }
        int l = solve(root -> left, result, maxDepth, depth + 1);
        int r = solve(root -> right, result, maxDepth, depth + 1);
        
        if(l == r){
            maxDepth = max(maxDepth, l);
            if(maxDepth == l){
                result = root;
            }
        }
        return max(l, r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        TreeNode* result;
        int maxDepth = -1;
        solve(root, result, maxDepth, 0);
        return result;
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
    bool solve(TreeNode* root, TreeNode* &ans, int depth){
        
        if(root == NULL){
            return false;
        }
        if(root -> left == NULL && root -> right == NULL){
            if(depth == 1){
                ans = root;
                return true;
            }
            return false;
        }
        bool l = solve(root -> left, ans, depth - 1);
        bool r = solve(root -> right, ans, depth - 1);
        
        if(l && r){
            ans = root;
            return true;
        }
        if(l || r){
            return true;
        }
        return false;
    }
    int findDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(findDepth(root -> left), findDepth(root -> right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if(root == NULL){
            return NULL;
        }
        
        int depth = findDepth(root);
        TreeNode* ans = NULL;
        solve(root, ans, depth);
        return ans;
    }
};
