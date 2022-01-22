//https://www.lintcode.com/problem/binary-tree-vertical-order-traversal/description
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
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    #define pti pair<TreeNode*,int>
    vector<vector<int>> verticalOrder(TreeNode * root) {
        
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        queue<pti> q;
        q.push({root, 0});

        map<int,vector<int>> mp;

        while(!q.empty()){
            pti p = q.front();
            q.pop();
            TreeNode* curr = p.first;
            int level = p.second;
            mp[level].push_back(curr -> val);

            if(curr -> left) q.push({curr -> left, level - 1});
            if(curr -> right) q.push({curr -> right, level + 1});
        }
        
        for(auto x: mp){
            res.push_back(x.second);
        }
        return res;
    }
};
