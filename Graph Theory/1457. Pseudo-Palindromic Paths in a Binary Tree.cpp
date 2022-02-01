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
    bool isPseudoPalindromic(vector<int> &num, int n){
      
        if(n % 2 != 0){
            bool flag = false;
            for(int i = 1; i <= 9; i++){
                if(num[i] % 2 != 0){
                    if(flag){
                        return false;
                    }
                    flag = true;
                }
            }
        }
        else{
            for(int i = 1; i <= 9; i++){
                if(num[i] % 2 != 0){
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(TreeNode* root, int len, vector<int> &num, int &count){
        
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            num[root -> val]++;
            if(isPseudoPalindromic(num, len + 1)){
                count++;
            }
            num[root -> val]--;
            return;
        }
        num[root -> val]++;
        dfs(root -> left, len + 1, num, count);
        dfs(root -> right, len + 1, num, count);
        num[root -> val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> num(10, 0);
        int count = 0, len = 0;
        dfs(root, len, num, count);
        return count;
    }
};
