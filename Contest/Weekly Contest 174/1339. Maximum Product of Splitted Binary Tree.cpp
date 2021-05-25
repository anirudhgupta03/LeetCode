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
    #define ll long long
    int solve(TreeNode* root, ll &sum, ll &res){
        
        if(root == NULL){
            return 0;
        }
        
        root -> val += solve(root -> left, sum,res) + solve(root -> right,sum,res);
        
        if((sum - root -> val)*(root -> val) > res){      //Product of the sum of entire subtree in which it is the root and sum of remaining tree
            res = (ll)(sum-root->val)*(root->val);
        }
        
        return root->val;
    }
    void totalSum(TreeNode* temp,ll &sum){
        
        if(temp == NULL){
            return;
        }
        
        sum += temp -> val;
        totalSum(temp -> left,sum);
        totalSum(temp -> right,sum);
        
    }
    int maxProduct(TreeNode* root) {
        
        int mod = 1e9 + 7;
        
        TreeNode* temp = root;
        
        ll sum = 0;
        
        totalSum(temp,sum);     //Sum of all the nodes of the tree
        
        ll res = INT_MIN;
        
        solve(root,sum,res);
        
        return res%(mod);
    }
};
