//https://www.lintcode.com/problem/854/
//Ref: https://www.youtube.com/watch?v=ZFoy1liwgeY
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root
     * @param k: an integer
     * @return: the value of the nearest leaf node to target k in the tree
     */
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &par, TreeNode* &start, int k){

        if(root == NULL){
            return;
        }
        if(root -> val == k){
            start = root;
        }
        par[root] = parent;
        dfs(root -> left, root, par, start, k);
        dfs(root -> right, root, par, start, k);
    }
    int findClosestLeaf(TreeNode * root, int k){

        unordered_map<TreeNode*, TreeNode*> par;
      
        TreeNode* start;
        dfs(root, NULL, par, start, k);

        queue<TreeNode*> q;
        q.push(start);

        unordered_set<TreeNode*> vis;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr -> left == NULL && curr -> right == NULL){
                return curr -> val;
            }
            if(vis.find(curr) != vis.end()){
                continue;
            }
            vis.insert(curr);
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
            if(par[curr]) q.push(par[curr]);
        }
        return -1;
    }
};
