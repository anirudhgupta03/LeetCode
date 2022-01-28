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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> res;
        
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int ele = INT_MIN;
            int sz = q.size();
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                
                ele = max(ele, curr -> val);
                
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            res.push_back(ele);
        }
        return res;
    }
};
