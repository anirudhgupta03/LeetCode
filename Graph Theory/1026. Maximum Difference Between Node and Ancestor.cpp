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
    void solve(TreeNode* root, int &maxDiff, int minVal, int maxVal){
        
        if(root == NULL){
            return;
        }
        
        minVal = min(minVal, root -> val);
        maxVal = max(maxVal, root -> val);
        
        maxDiff = max(maxDiff, maxVal - minVal);
        
        solve(root -> left, maxDiff, minVal, maxVal);
        solve(root -> right, maxDiff, minVal, maxVal);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int maxDiff = 0;
        
        solve(root, maxDiff, INT_MAX, INT_MIN);
        
        return maxDiff;
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
    int maxDiff;
    pair<int,int> solve(TreeNode* root){
        
        if(root == NULL){
            return {INT_MAX, INT_MIN};
        }
        
        if(root -> left == NULL && root -> right == NULL){
            return {root -> val, root -> val};
        }
        pair<int,int> l = solve(root -> left);
        pair<int,int> r = solve(root -> right);
        
        int minVal = min(l.first, r.first);
        int maxVal = max(l.second, r.second);
        
        maxDiff = max({maxDiff, abs(root -> val - minVal), abs(root -> val - maxVal)});
        
        return {min(minVal, root -> val), max(maxVal, root -> val)};
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = INT_MIN;
        solve(root);
        return maxDiff;
    }
};
