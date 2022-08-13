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
    #define ppp pair<pii,pii>
    #define pii pair<int,int>
    int ans;
    ppp solve(TreeNode* root){
        
        if(root == NULL){
            return {{1,0},{INT_MIN, INT_MAX}};  //<max,min>
        }
        if(root -> left == NULL && root -> right == NULL){
            ans = max(ans, root -> val);
            return {{1,root -> val},{root -> val, root -> val}};
        }
        
        ppp l = solve(root -> left);
        ppp r = solve(root -> right);
        
        if(l.first.first && r.first.first){
            if(root -> val > l.second.first && root -> val < r.second.second){
                ans = max(ans, root -> val + l.first.second + r.first.second);
                int rval = (l.second.second == INT_MAX) ? root -> val : l.second.second;
                int lval = (r.second.first == INT_MIN) ? root -> val : r.second.first;
                return {{1,root -> val + l.first.second + r.first.second}, {lval, rval}};
            }
        }
        return {{0,-1},{-1,-1}};
    }
    int maxSumBST(TreeNode* root) {
        
        ans = 0;
        solve(root);
        return ans;
    }
};
