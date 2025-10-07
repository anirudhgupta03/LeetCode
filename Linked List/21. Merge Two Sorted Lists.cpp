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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* root = new ListNode(-1);
        ListNode* pre = root;
        ListNode* ptr1 = list1, *ptr2 = list2;

        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1 -> val < ptr2 -> val){
                ListNode* nextNode = ptr1 -> next;
                pre -> next = ptr1;
                ptr1 -> next = NULL;
                pre = ptr1;
                ptr1 = nextNode;
            }
            else{
                ListNode* nextNode = ptr2 -> next;
                pre -> next = ptr2;
                ptr2 -> next = NULL;
                pre = ptr2;
                ptr2 = nextNode;
            }
        }
        
        if(ptr1 != NULL) pre -> next = ptr1;
        if(ptr2 != NULL) pre -> next = ptr2;
        return root -> next;
    }
};
