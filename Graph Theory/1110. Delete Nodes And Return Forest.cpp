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
    bool solve(TreeNode* root, unordered_map<int,int> &umap, vector<TreeNode*> &res){
        
        if(root == NULL){
            return true;
        }
        
        bool l = solve(root -> left, umap, res);
        bool r = solve(root -> right, umap, res);
        
        if(l){
            root -> left = NULL;
        }
        if(r){
            root -> right = NULL;
        }
        if(umap[root -> val]){
            if(root -> left) res.push_back(root -> left);
            if(root -> right) res.push_back(root -> right);
            return true;
        }
        return false;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int> umap;
        for(auto x: to_delete) umap[x]++;
        vector<TreeNode*> res;
        bool flag = solve(root, umap, res);
        if(!flag){
            res.push_back(root);
        }
        return res;
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
    TreeNode* solve(TreeNode* root, vector<TreeNode*> &res, unordered_set<int> &us){
        
        if(root == NULL){
            return NULL;
        }
        
        TreeNode* l = solve(root -> left, res, us);
        TreeNode* r = solve(root -> right, res, us);
        
        if(us.find(root -> val) != us.end()){
            if(l) res.push_back(l);
            if(r) res.push_back(r);
            return NULL;
        }
        else{
            root -> left = l;
            root -> right = r;
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> us;
        for(auto &x: to_delete){
            us.insert(x);
        }
        vector<TreeNode*> res;
        root = solve(root, res, us);
        if(root) res.push_back(root);
        return res;
    }
};
