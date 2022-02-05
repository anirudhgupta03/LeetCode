//Ref: https://www.youtube.com/watch?v=nxHBg7hm0rs
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
    string solve(TreeNode* root, unordered_map<string,int> &umap, vector<TreeNode*> &res){
        
        if(root == NULL){
            return "X";
        }
        
        string l = solve(root -> left, umap, res);
        string r = solve(root -> right, umap, res);
        string temp = to_string(root -> val) + " " + l + " " + r;
        
        umap[temp]++;
        if(umap[temp] == 2){
            res.push_back(root);
        }
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> res;
        
        if(root == NULL){
            return res;
        }
        
        unordered_map<string,int> umap;
        
        solve(root, umap, res);
        
        return res;
    }
};
