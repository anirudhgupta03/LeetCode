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
    int solve(TreeNode* root, unordered_map<int,int> &freq){
        
        if(root == NULL){
            return 0;
        }
        int l = solve(root -> left, freq);
        int r = solve(root -> right, freq);
        
        freq[root -> val + l + r]++;
        return root -> val + l + r;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int,int> freq;
        
        solve(root, freq);
        
        int max_freq = 0;
        
        for(auto x: freq){
            max_freq = max(max_freq, x.second);
        }
        
        vector<int> res;
        
        for(auto x: freq){
            if(x.second == max_freq){
                res.push_back(x.first);
            }
        }
        return res;
    }
};
