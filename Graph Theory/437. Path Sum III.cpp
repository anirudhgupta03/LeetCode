//Ref: https://www.youtube.com/watch?v=UQzXYDN49cs
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
    void helper(TreeNode* root, int sum, int &ans){
        if(root == NULL) return;
        if(sum == root -> val) ans++;
        sum = sum - root -> val;
        helper(root -> left, sum, ans);
        helper(root -> right, sum, ans);
    }
    void solve(TreeNode* root, int sum, int &ans){
        if(root == NULL){
            return;
        }
        helper(root, sum, ans);
        solve(root -> left, sum, ans);
        solve(root -> right, sum, ans);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        int ans = 0;
        solve(root, sum, ans);
        return ans;
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
    unordered_map<long ,long> umap;
    int count;
    void solve(TreeNode* root, long sum, long targetSum){
        
        if(root == NULL){
            return;
        }
        if(umap[sum + root -> val - targetSum]){
            count += umap[sum + root -> val - targetSum];
        }
        
        umap[sum + root -> val]++;
        solve(root -> left, sum + root -> val, targetSum);
        solve(root -> right, sum + root -> val, targetSum);
        umap[sum + root -> val]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        umap.clear();
        umap[0] = 1;
        count = 0;
        solve(root, 0, targetSum);
        return count;
    }
};
