//Method - 1
//https://leetcode.com/problems/linked-list-in-binary-tree/discuss/524842/Concise-10-lines-C%2B%2B-Recursion-solution.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool helper(ListNode* head, TreeNode* root){
        
        if(head == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        if(head -> val != root -> val){
            return false;
        }
        return helper(head -> next, root -> left) || helper(head -> next, root -> right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(helper(head, root)){
            return true;
        }
        
        if(head == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        return isSubPath(head, root -> left) || isSubPath(head, root -> right);
    }
};

//Method - 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    map<pair<ListNode*,TreeNode*>,bool> dp;
    bool solve(ListNode* head, ListNode* curr, TreeNode* root){
        
        if(curr == NULL) return true;
        if(root == NULL) return false;
        
        if(dp.find({curr, root}) != dp.end()){
            return dp[{curr, root}];
        }
        if(curr -> val == root -> val){
            bool flag = solve(head, curr -> next, root -> left) || solve(head, curr -> next, root -> right);
            if(flag) return dp[{curr,root}] = true;
        }
        
        if(head -> val == root -> val){
            bool flag = solve(head, head -> next, root -> left) || solve(head, head -> next, root -> right);
            if(flag) return dp[{curr,root}] = true;
        }
        
        bool flag = solve(head, head, root -> left) || solve(head, head, root -> right);
        return dp[{curr,root}] = flag;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        dp.clear();
        return solve(head, head, root);
    }
};
