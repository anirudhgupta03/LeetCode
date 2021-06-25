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
    ListNode* merge(ListNode* p1, ListNode* p2){
        
        if(p1 == NULL){
            return p2;
        }
        if(p2 == NULL){
            return p1;
        }
        if(p1 == NULL && p2 == NULL){
            return NULL;
        }
        
        ListNode* head, *prev = NULL;
        
        while(p1 && p2){
            
            if(p1 -> val < p2 -> val){
                if(prev == NULL){
                    head = p1;
                    prev = head;
                }
                else{
                    prev -> next = p1;
                    prev = p1;
                }
                p1 = p1 -> next;
            }
            else{
                if(prev == NULL){
                    head = p2;
                    prev = head;
                }
                else{
                    prev -> next = p2;
                    prev = p2;
                }
                p2 = p2 -> next;
            }
        }
        
        if(p1){
            prev -> next = p1;
        }
        
        if(p2){
            prev -> next = p2;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* slow = head, *fast = head, *prev;
        
        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        prev -> next = NULL;
        return merge(sortList(head), sortList(slow));
    }
};
