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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int sz = q.size();
            long long mmin = q.front().second;
            long long first = 0, last = 0;
            while(sz--){
                TreeNode* curr = q.front().first;
                long long level = q.front().second;
                q.pop();
                last = level - mmin;
                if(curr -> left){
                    q.push({curr -> left, last*2 + 1});
                }
                if(curr -> right){
                    q.push({curr -> right, last*2 + 2});
                }
            }
            ans = max(ans, (int)(last - first + 1));
        }
        return ans;
    }
};
