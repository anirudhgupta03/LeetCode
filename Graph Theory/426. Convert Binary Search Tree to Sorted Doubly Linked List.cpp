//https://www.lintcode.com/problem/1534/
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
     * @param root: root of a tree
     * @return: head node of a doubly linked list
     */
    pair<TreeNode*,TreeNode*> solve(TreeNode* root){
        if(root == NULL){
            return {NULL,NULL};
        }

        if(root -> left == NULL && root -> right == NULL){
            return {root,root};
        }

        pair<TreeNode*,TreeNode*> lefttree = solve(root -> left);
        pair<TreeNode*,TreeNode*> righttree = solve(root -> right);

        TreeNode* node1 = lefttree.first, *node2 = lefttree.second , *node3 = righttree.first, *node4 = righttree.second;

        root -> left = node2;
        root -> right = node3;

        if(node2) node2 -> right = root;
 
        if(node3) node3 -> left = root;
        
        if(node1 && node4) return {node1, node4};
        
        if(node1) return {node1, root};
        
        if(node4) return {root, node4};
        
        return {root,root};
    }
    TreeNode * treeToDoublyList(TreeNode * root) {
        
        solve(root);

        TreeNode* temp = root, *start,  *end;
        while(temp -> left){
            temp = temp -> left;
        }
        start = temp;

        temp = root;
        while(temp -> right){
            temp = temp -> right;
        }
        end = temp;
        start -> left = end;
        end -> right = start;
        return start;
    }
};
