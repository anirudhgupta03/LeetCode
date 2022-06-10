//Ref: https://www.youtube.com/watch?v=VYczyMiMTqA
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
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        
        vector<TreeNode*> res;
        
        for(int i = 1; i < n; i += 2){
            vector<TreeNode*> l = allPossibleFBT(i);
            vector<TreeNode*> r = allPossibleFBT(n - i - 1);
            
            for(auto x: l){
                for(auto y: r){
                    TreeNode* root = new TreeNode(0);
                    root -> left = x;
                    root -> right = y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
