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
    ListNode* reverseList(ListNode* temp){
        
        ListNode* temp1 = NULL, *temp2 = temp, *temp3 = temp -> next;
        while(temp3){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
        }
        temp2 -> next = temp1;
        return temp2;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL ||  head -> next -> next == NULL){
            return;
        }
        
        ListNode* temp1 = head, *temp2 = head;
        ListNode* pre;
        while(temp1 && temp2 && temp2 -> next){
            pre = temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next -> next;
        }
        
        pre -> next = NULL;
        temp1 = reverseList(temp1);
        temp2 = temp1;
        temp1 = head;
        
        while(temp1 && temp2){
            ListNode* t1 = temp1 -> next, *t2 = temp2 -> next;
            temp1 -> next = temp2;
            temp2 -> next =  t1;
            pre = temp2;
            temp2 = t2;
            temp1 = t1;
        }
        if(temp2){
            pre -> next = temp2;
        }
    }
};
