//Method - 1
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

//Method - 2
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
    int count;
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &par, vector<TreeNode*> &leaf){
        par[root] = parent;
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            leaf.push_back(root);
        }
        dfs(root -> left, root, par, leaf);
        dfs(root -> right, root, par, leaf);
    }
    void dfs(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &par, int distance){
        
        if(node == NULL){
            return;
        }
        if(node -> left == NULL && node -> right == NULL){
            if(distance >= 0){
                count++;
            }
        }
        
        if(par[node] != parent) dfs(par[node], node, par, distance - 1);
        
        if(node -> left && (node -> left) != parent) dfs(node -> left, node, par, distance - 1);
        
        if(node -> right && (node -> right) != parent) dfs(node -> right, node, par, distance - 1);
    }
    int countPairs(TreeNode* root, int distance) {
        
        unordered_map<TreeNode*,TreeNode*> par;
        vector<TreeNode*> leaf;
        dfs(root, NULL, par, leaf);
        count = 0;
        
        for(auto &x: leaf){
            dfs(x, NULL, par, distance);
            count--;
        }
        return count/2;
    }
};
