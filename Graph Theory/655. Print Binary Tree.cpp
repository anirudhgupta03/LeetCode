//Method - 1
//Using BFS
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
    #define ptpii pair<TreeNode*,pair<int,int>>
    vector<vector<string>> printTree(TreeNode* root) {
        
        int level = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            level++;
        }
        
        int m = level, n = pow(2,level) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        
        queue<ptpii> que;
        que.push({root,{0, (n - 1)/2}});
        
        while(!que.empty()){
            
            ptpii p = que.front();
            TreeNode* curr = p.first;
            int r = p.second.first, c = p.second.second;
            res[r][c] = to_string(curr -> val);
            que.pop();
            
            if(curr -> left){
                que.push({curr -> left,{r + 1, c - pow(2, level - r - 2)}});
            }
            if(curr -> right){
                que.push({curr -> right,{r + 1, c + pow(2, level - r - 2)}});
            }
        }
        return res;
    }
};

//Method - 2
//Using DFS
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
    int findHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(findHeight(root -> left), findHeight(root -> right));
    }
    void solve(TreeNode* root, int r, int c, int ht, vector<vector<string>> &res){
        if(root == NULL){
            return;
        }
        res[r][c] = to_string(root -> val);
        if(root -> left) solve(root -> left, r + 1, c - (1 << (ht - r - 1)), ht, res);
        if(root -> right) solve(root -> right, r + 1, c + (1 << (ht - r - 1)), ht, res);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        
        int ht = findHeight(root);
        int m = ht;
        int n = (1 << ht) - 1;
        
        vector<vector<string>> res(m, vector<string>(n,""));
        solve(root, 0, n/2, ht - 1, res);
        return res;
    }
};
