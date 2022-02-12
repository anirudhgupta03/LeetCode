//Ref: https://www.youtube.com/watch?v=yYcKQdGEdDY
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
    int count;
    void solve(TreeNode* curr, TreeNode* par){
        
        if(curr == NULL){
            return;
        }
        solve(curr -> left, curr);
        solve(curr -> right, curr);
        if(curr -> val > 1){
            int extracoins = curr -> val - 1;
            curr -> val = 1;
            if(par){
                par -> val += extracoins;
            }
            count += extracoins;
        }
        else if(curr -> val < 1){
            int neededcoins = 1 - curr -> val;
            curr -> val = 1;
            if(par){
                par -> val -= neededcoins;
            }
            count += neededcoins;
        }
    }
    int distributeCoins(TreeNode* root) {
        count  = 0;
        solve(root, NULL);
        return count;
    }
};
