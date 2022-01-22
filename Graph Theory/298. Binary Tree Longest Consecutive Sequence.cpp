//Ref: https://www.lintcode.com/problem/595/
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
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    pair<int,int> solve(TreeNode* root, int &maxLen){

        if(root == NULL){
            return {-1,0};
        }
        if(root -> left == NULL && root -> right == NULL){
            return {root -> val, 1};
        }

        pair<int,int> p1 = solve(root -> left, maxLen);
        pair<int,int> p2 = solve(root -> right, maxLen);

        if(p1.first == -1 && p2.first == -1){
            return {root -> val, 1};
        }
        else if(p1.first != -1 && p2.first != -1){
            int len = 0;
            if(p1.first - root -> val == 1){
                len = p1.second;
            }
            if(p2.first - root -> val == 1){
                len = max(len, p2.second);
            }
            maxLen = max(maxLen, len + 1);
            return {root -> val, len + 1};
        }
        else if(p1.first != -1){
            int len = 0;
            if(p1.first - root -> val == 1){
                len = p1.second;
            }
            maxLen = max(maxLen, len + 1);
            return {root -> val, len + 1};
        }
        else if(p2.first != -1){
            int len = 0;
            if(p2.first - root -> val == 1){
                len = p2.second;
            }
            maxLen = max(maxLen, len + 1);
            return {root -> val, len + 1};
        }
    }
    int longestConsecutive(TreeNode * root) {
        
        if(root == NULL){
            return NULL;
        }
        int maxLen = 1;
        solve(root, maxLen);
        return maxLen;
    }
};
