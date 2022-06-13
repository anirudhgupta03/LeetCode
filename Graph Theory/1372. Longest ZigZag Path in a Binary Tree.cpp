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
    int solve(TreeNode* root, int flag, int &maxLen){
        
        if(root == NULL){
            return 0;
        }
        
        int l = solve(root -> left, 0, maxLen);
        int r = solve(root -> right, 1, maxLen);
        maxLen = max(maxLen, max(l + 1, r + 1));
        
        if(flag == 0){
            return r + 1;
        }
        if(flag == 1){
            return l + 1;
        }
        return 0;
    }
    int longestZigZag(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int maxLen = 1;
        solve(root, -1, maxLen);
        return maxLen - 1;
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
    int ans;
    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            return {-1,-1};
        }
        if(root -> left == NULL && root -> right == NULL){
            return {0,0};
        }
        pair<int,int> l = solve(root -> left);
        pair<int,int> r = solve(root -> right);
        
        int lval = l.second + 1;
        int rval = r.first + 1;
        ans = max({ans,lval, rval});
        
        return {lval, rval};
    }
    int longestZigZag(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        ans = 0;
        solve(root);
        return ans;
    }
};
