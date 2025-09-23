//Method - 1
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
    ListNode* mergeSortedList(ListNode* ptr1, ListNode* ptr2){
        
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;
        
        while(ptr1 && ptr2){
            if(ptr1 -> val < ptr2 -> val){
                ptr -> next = ptr1;
                ptr1 = ptr1 -> next;   
            }
            else{
                ptr -> next = ptr2;
                ptr2 = ptr2 -> next;
            }
            ptr = ptr -> next;
        }
        while(ptr1){
            ptr -> next = ptr1;
            ptr1 = ptr1 -> next;   
            ptr = ptr -> next;
        }
        while(ptr2){
            ptr -> next = ptr2;
            ptr2 = ptr2 -> next;
            ptr = ptr -> next;
        }
        return head -> next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* slow = head, *fast = head, *pre = NULL;
        while(fast != NULL && fast -> next != NULL){
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        pre -> next = NULL;
        return mergeSortedList(sortList(head), sortList(slow));
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
