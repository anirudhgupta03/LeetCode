//Ref: https://www.youtube.com/watch?v=n0mT5rfeI0s
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
    int id = 0;
    TreeNode* buildTree(string s, int depth){
        if(id == s.size()){
            return NULL;
        }
        int cd = 0;
        string temp;
        int idx = id;
        while(idx < s.size() && s[idx] == '-'){
            cd++;
            idx++;
        }
        if(cd != depth){
            return NULL;
        }
        while(idx < s.size() && s[idx] != '-'){
            temp.push_back(s[idx]);
            idx++;
        }
        id = idx;
        TreeNode* root = new TreeNode(stoi(temp));
        root -> left = buildTree(s, depth + 1);
        root -> right = buildTree(s, depth + 1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return buildTree(traversal, 0);
    }
};
