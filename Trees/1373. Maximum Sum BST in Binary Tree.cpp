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
    #define pii pair<int,int>
    pair<pii,pii> solve(TreeNode* root, int &maxSum){
        if(root == NULL){
            return {{true,0},{INT_MIN, INT_MAX}};
        }
        pair<pii,pii> l = solve(root -> left, maxSum);
        pair<pii,pii> r = solve(root -> right, maxSum);
        
        if(l.first.first && r.first.first){
            int lmax = l.second.first, rmin = r.second.second;
            if(lmax < root -> val && rmin > root -> val){
                maxSum = max(maxSum, l.first.second + r.first.second + root -> val);
                return {{true,l.first.second + r.first.second + root -> val}, {max(root -> val, r.second.first), min(root -> val, l.second.second)}};
            }
        }
        return {{false,-1},{-1,-1}};
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};
