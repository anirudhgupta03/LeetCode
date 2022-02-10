//Ref: https://www.youtube.com/watch?v=P_Y1dGLcHUU
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
    int ind;
    vector<int> res;
    bool dfs(TreeNode* node, vector<int> &voyage){
        if(node == NULL){
            return true;
        }
        if(node -> val != voyage[ind]){
            return false;
        }
        ind++;
        if(node -> left && node -> left -> val != voyage[ind]){
            res.push_back(node -> val);
            return dfs(node -> right, voyage) && dfs(node -> left, voyage);
        }
        else{
            return dfs(node -> left, voyage) && dfs(node -> right, voyage);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        ind = 0;
        res.clear();
        
        bool flag = dfs(root, voyage);
        if(flag){
            return res;
        }
        else{
            return {-1};
        }
    }
};
