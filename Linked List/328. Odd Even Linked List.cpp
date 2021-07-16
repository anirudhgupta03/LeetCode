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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL){
            return head;
        }
        ListNode* temp1 = head, *temp2 = head -> next, *prev;
        ListNode* root1 = temp1, *root2 = temp2;
        
        while(temp1 && temp2){
            
            temp1 -> next = temp2 -> next;
            prev = temp1;
            temp1 = temp2 -> next;
            
            if(temp1 != NULL){
                temp2 -> next = temp1 -> next;
                temp2 = temp1 -> next;
            }
        }
        
        if(temp1 != NULL) temp1 -> next = root2;
        else prev -> next = root2;
        return root1;
    }
};
