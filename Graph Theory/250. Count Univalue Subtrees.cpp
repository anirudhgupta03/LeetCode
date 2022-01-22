//https://www.lintcode.com/problem/921/
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
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
    pair<int,int> solve(TreeNode* root, int &count){

        if(root == NULL){
            return {-1,1};
        }
        if(root -> left == NULL && root -> right == NULL){
            count++;
            return {root -> val,0};
        }

        pair<int,int> p1 = solve(root -> left, count);
        pair<int,int> p2 = solve(root -> right, count);

        if(p1.first != -1 && p2.first != -1){
            if(root -> val == p1.first && root -> val == p2.first){
                count++;
                return {root -> val, 0};
            }
        }
        else if(p1.first == -1 && p2.first == -1){
            int flag1 = p1.second, flag2 = p2.second;
            if(flag1 && flag2){
                count++;
                return {root -> val, 0};
            }
        }
        else if(p1.first == -1){
            int flag1 = p1.second;
            if(flag1 && root -> val == p2.first){
                count++;
                return {root -> val, 0};
            }
        }
        else if(p2.first == -1){
            int flag2 = p2.second;
            if(flag2 && root -> val == p1.first){
                count++;
                return {root -> val,0};
            }
        }
        return {-1,0};
    }
    int countUnivalSubtrees(TreeNode * root) {
        
        int count = 0;
        solve(root, count);
        return count;
    }
};
