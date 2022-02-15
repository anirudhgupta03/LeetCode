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
    TreeNode* buildTree(int lo, int hi, vector<int> &v){
        
        if(lo > hi){
            return NULL;
        }
        
        int mid = (lo + hi)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root -> left = buildTree(lo, mid - 1, v);
        root -> right = buildTree(mid + 1, hi, v);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
    
        ListNode* temp = head;
        vector<int> v;
        while(temp){
            v.push_back(temp -> val);
            temp = temp -> next;
        }
        
        return buildTree(0, v.size() - 1, v);
    }
};
