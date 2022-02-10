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
    void solve(TreeNode* root, string &res, string &temp){
        
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            temp.push_back(root -> val + 'a');
            reverse(temp.begin(), temp.end());
            if(res == ""){
                res = temp;
            }
            else if(temp < res){
                res = temp;
            }
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            return;
        }
        temp.push_back(root -> val + 'a');
        solve(root -> left, res, temp);
        solve(root -> right, res, temp);
        temp.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        
        string res, temp;
        solve(root, res, temp);
        return res;
    }
};
