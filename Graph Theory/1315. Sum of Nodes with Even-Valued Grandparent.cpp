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
    void dfs(TreeNode* curr, TreeNode* parent, unordered_map<TreeNode*,TreeNode*> &par){
        
        if(curr == NULL){
            return;
        }
        par[curr] = parent;
        dfs(curr -> left, curr, par);
        dfs(curr -> right, curr, par);
    }
    int sumEvenGrandparent(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        unordered_map<TreeNode*,TreeNode*> par;
        dfs(root, NULL, par);
        
        int sum = 0;
        
        for(auto &x: par){
            if(x.second == NULL) continue;
            if(par[x.second] == NULL) continue;
            if((par[x.second] -> val)%2 == 0){
                sum += (x.first) -> val;
            }
        }
        return sum;
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
    int sumEvenGrandparent(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        queue<pair<TreeNode*,pair<TreeNode*,TreeNode*>>> q;
        
        q.push({root,{NULL, NULL}});
        
        int sum = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                TreeNode* curr = q.front().first, *parent = q.front().second.first, *grandparent = q.front().second.second;
                q.pop();
                
                if(grandparent && (grandparent -> val) % 2 == 0){
                    sum += curr -> val;
                }
                if(curr -> left) q.push({curr -> left,{curr, parent}});
                if(curr -> right) q.push({curr -> right, {curr, parent}});
            }
        }
        return sum;
    }
};
