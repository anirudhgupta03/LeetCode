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
    vector<TreeNode*> solve(int n){
        
        if(n == 1){
            vector<TreeNode*> temp;
            temp.push_back(new TreeNode(0));
            return temp;
        }
        
        vector<TreeNode*> v;
        for(int i = 1; i < n; i += 2){
            vector<TreeNode*> l = solve(i);
            vector<TreeNode*> r = solve(n - i - 1);
            for(auto x: l){
                for(auto y: r){
                   TreeNode* curr = new TreeNode(0);
                    curr -> left = x;
                    curr -> right = y;
                    v.push_back(curr);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};
