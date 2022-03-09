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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* root = NULL, *pre = NULL;
        
        while(head){
            if(head -> next){
                if(head -> next -> val == head -> val){
                    int tval = head -> val;
                    while(head && head -> val == tval) head = head -> next;
                }
                else{
                    if(root == NULL){
                        root = head;
                        pre = head;
                    }
                    else{
                        pre -> next = head;
                        pre = head;
                    }
                    head = head -> next;
                }
            }
            else{
                if(root == NULL){
                    root = head;
                    pre = head;
                }
                else{
                    pre -> next = head;
                    pre = head;
                    break;
                }
            }
        }
        if(pre)
        pre -> next = NULL;
        return root;
    }
};
