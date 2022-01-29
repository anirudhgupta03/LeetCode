//Ref: https://www.youtube.com/watch?v=R9qiY7OK9JQ
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
    #define pti pair<TreeNode*,int>
    #define ll long long
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        queue<pti> q;
        q.push({root,0});
        
        ll width = 1;
        
        while(!q.empty()){
            int sz = q.size();
            ll l = -1, r = -1;
            bool flag = false;
            while(sz--){
                pti p = q.front();
                q.pop();
                
                TreeNode* curr = p.first;
                ll level = p.second;
                
                if(!flag){
                    l = p.second;
                    flag = true;
                }
                if(flag){
                    r = p.second;
                }
                if(curr -> left) q.push({curr -> left, 2*level + 1});
                if(curr -> right) q.push({curr -> right, 2*level + 2});
            }
            width = max(width, r - l + 1);
        }
        return width;
    }
};
