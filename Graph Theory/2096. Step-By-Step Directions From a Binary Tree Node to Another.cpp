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
    unordered_map<TreeNode*,TreeNode*> par;
    int n;
    void solve(TreeNode* curr, TreeNode* parent, TreeNode* &start, int startValue){
        if(curr == NULL){
            return;
        }
        par[curr] = parent;
        n++;
        if(curr -> val == startValue){
            start = curr;
        }
        solve(curr -> left, curr, start, startValue);
        solve(curr -> right, curr, start, startValue);
    }
    bool dfs(TreeNode* curr, string &path, string &res, int destValue, vector<int> &vis){
        
        if(curr == NULL){
            return false;
        }
        if(curr -> val == destValue){
            res = path;
            return true;
        }
        if(vis[curr -> val]) return false;
        vis[curr -> val] = 1; 
        
        path.push_back('U');
        bool flag = dfs(par[curr], path, res, destValue, vis);
        if(flag) return true;
        path.pop_back();
        
        path.push_back('R');
        flag = dfs(curr -> right, path, res, destValue, vis);
        if(flag) return true;
        path.pop_back();
        
        path.push_back('L');
        flag = dfs(curr -> left, path, res, destValue, vis);
        if(flag) return true;
        path.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        n = 0;
        TreeNode* start;
        solve(root, NULL, start, startValue);
        string path, res;
        vector<int> vis(n + 1,0);
        dfs(start, path, res, destValue, vis);
        return res;
    }
};
