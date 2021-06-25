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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        
        if(l1 -> val > l2 -> val){
            swap(l1,l2);
        }
        
        ListNode* head, *prev = NULL;
        
        while(l1 != NULL && l2 != NULL){
            
            if(l1 -> val < l2 -> val){
                if(prev == NULL){
                    head = l1;
                    prev = head;
                }
                else{
                    prev -> next = l1;
                    prev = l1;
                }
                l1 = l1 -> next;
            }
            else{
                if(prev == NULL){
                    head = l2;
                    prev = head;
                }
                else{
                    prev -> next = l2;
                    prev = l2;
                }
                l2 = l2 -> next;
            }
        }
         
        if(l1){
            prev -> next = l1;
        }
        if(l2){
            prev -> next = l2;
        }
        return head;
    }
};
