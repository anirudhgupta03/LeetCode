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
    void dfs(TreeNode* curr, TreeNode* parent, unordered_map<TreeNode*,TreeNode*> &par){
        
        if(curr == NULL){
            return;
        }
        par[curr] = parent;
        dfs(curr -> left, curr, par);
        dfs(curr -> right, curr, par);
    }
    int sumEvenGrandparent(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        unordered_map<TreeNode*,TreeNode*> par;
        dfs(root, NULL, par);
        
        int sum = 0;
        
        for(auto &x: par){
            if(x.second == NULL) continue;
            if(par[x.second] == NULL) continue;
            if((par[x.second] -> val)%2 == 0){
                sum += (x.first) -> val;
            }
        }
        return sum;
    }
};
