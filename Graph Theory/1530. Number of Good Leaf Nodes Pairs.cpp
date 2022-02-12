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
    vector<TreeNode*> leafnodes;
    unordered_map<TreeNode*, TreeNode*> par;
    int count;
    bool flag;
    void solve(TreeNode* root, TreeNode* parent){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            leafnodes.push_back(root);
        }
        par[root] = parent;
        solve(root -> left, root);
        solve(root -> right, root);
    }
    void dfs(int dist, TreeNode* root, unordered_set<TreeNode*> &vis, int distance){
        if(root == NULL || dist > distance || vis.find(root) != vis.end()){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            if(!flag){
                flag = true;
            }
            else{
                count++;
                vis.insert(root);
                return;
            }
        }
        vis.insert(root);
        dfs(dist + 1, par[root], vis, distance);
        dfs(dist + 1, root -> left, vis, distance);
        dfs(dist + 1, root -> right, vis, distance);
    }
    int countPairs(TreeNode* root, int distance) {
        leafnodes.clear();
        par.clear();
        solve(root,NULL);
        count = 0;
        for(TreeNode* curr: leafnodes){
            unordered_set<TreeNode*> vis;
            flag = false;
            dfs(0, curr, vis, distance);
        }
        return count/2;
    }
};
