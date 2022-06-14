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
    int count;
    void solve(TreeNode* root, vector<int> &path){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            path[root -> val]++;
            int odd = 0;
            for(int i = 1; i <= 9; i++){
                if(path[i] % 2 != 0){
                    odd++;
                }
            }
            if(odd <= 1) count++;
            path[root -> val]--;
            return;
        }
        path[root -> val]++;
        solve(root -> left, path);
        solve(root -> right, path);
        path[root -> val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        count = 0;
        vector<int> path(10,0);
        solve(root, path);
        return count;
    }
};
