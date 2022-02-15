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
    TreeNode* buildTree(vector<int> &nums, int lo, int hi){
        
        if(lo > hi){
            return NULL;
        }
        int ind = lo, val = nums[lo];
        for(int i = lo + 1; i <= hi; i++){
            if(nums[i] > val){
                ind = i;
                val = nums[i];
            }
        }
        TreeNode* root = new TreeNode(nums[ind]);
        root -> left = buildTree(nums, lo, ind - 1);
        root -> right = buildTree(nums, ind + 1, hi);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums,0,nums.size() - 1);
    }
};
