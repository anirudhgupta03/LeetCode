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
