//Ref1: https://leetcode.com/problems/longest-univalue-path/discuss/650435/Simple-C%2B%2B-and-Python-solution-with-explanation
//Ref2: https://www.youtube.com/watch?v=AxKs4XVyAss
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
    pii dfs(TreeNode* node, int &ans){
        
        if(node == NULL){
            return {INT_MIN, 0};
        }
        
        pii left = dfs(node -> left, ans);
        pii right = dfs(node -> right, ans);
        pii p;
        
        if(node -> val == left.first && node -> val == right.first){
            ans = max(ans, left.second + right.second + 1);
            p = {node -> val, max(left.second,right.second) + 1};
        }
        else if(node -> val != left.first && node -> val != right.first){
            ans = max(ans, 1);
            p = {node -> val, 1};
        }
        else if(node -> val == left.first){
            ans = max(ans, left.second + 1);
            p = {node -> val, left.second + 1};
        }
        else{
            ans = max(ans, right.second + 1);
            p = {node -> val, right.second + 1};
        }
        return p;
    }
    int longestUnivaluePath(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        dfs(root,ans);
        return ans - 1;
    }
};
