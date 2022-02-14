//Ref: https://www.youtube.com/watch?v=EHOpJOjb7dY
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
    vector<TreeNode*> solve(int lo, int hi){
        if(lo > hi){
            return {NULL};
        }
        
        vector<TreeNode*> temp;
        for(int i = lo; i <= hi; i++){
            vector<TreeNode*> l = solve(lo, i - 1);
            vector<TreeNode*> r = solve(i + 1, hi);
            for(auto lt: l){
                for(auto rt: r){
                    TreeNode* node = new TreeNode();
                    node -> val = i;
                    node -> left = lt;
                    node -> right = rt;
                    temp.push_back(node);
                }
            }
        }
        return temp;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};
