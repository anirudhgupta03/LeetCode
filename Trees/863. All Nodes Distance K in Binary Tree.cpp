//Using DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* curr, TreeNode* par, unordered_map<TreeNode*, TreeNode*> &mpp){
        if(curr == NULL) return;
        mpp[curr] = par;
        solve(curr -> left, curr, mpp);
        solve(curr -> right, curr, mpp);
    }
    void findNodesAtDistanceK(TreeNode* curr, unordered_map<TreeNode*, TreeNode*> &mpp, int k, vector<int> &res, unordered_set<TreeNode*> &vis){
        if(curr == NULL || vis.find(curr) != vis.end()) return;
        vis.insert(curr);
        if(k == 0){
            res.push_back(curr -> val);
            return;
        }
        findNodesAtDistanceK(curr -> left, mpp, k - 1, res, vis);
        findNodesAtDistanceK(curr -> right, mpp, k - 1, res, vis);
        findNodesAtDistanceK(mpp[curr], mpp, k - 1, res, vis);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        solve(root, NULL, mpp);
        vector<int> res;
        unordered_set<TreeNode*> vis;
        findNodesAtDistanceK(target, mpp, k, res, vis);
        return res;
    }
};

//Using BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* curr, TreeNode* parent, unordered_map<TreeNode*,TreeNode*> &par){
        if(curr == NULL){
            return;
        }
        par[curr] = parent;
        dfs(curr -> left, curr, par);
        dfs(curr -> right, curr, par);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> res;
        
        if(root == NULL){
            return res;
        }
        
        unordered_map<TreeNode*,TreeNode*> par;
        
        dfs(root, NULL, par);
        
        queue<TreeNode*> q;
        q.push(target);
        
        unordered_set<TreeNode*> us;
        
        k++;
        while(!q.empty()){
            int sz = q.size();
            k--;
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                
                if(us.find(curr) != us.end()) continue;
                us.insert(curr);
                
                if(k == 0) res.push_back(curr -> val); 
                if(par[curr]) q.push(par[curr]);
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            if(k == 0) break;
        }
        return res;
    }
};
