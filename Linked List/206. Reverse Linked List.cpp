//Ref: https://www.youtube.com/watch?v=D2vI2DNJGd8&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=10

//Method - 1 (Iterative)
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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* temp1 = NULL, *temp2 = head, *temp3 = head -> next;
        
        while(temp3){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
        }
        
        temp2 -> next = temp1;
        return temp2;
    }
};

//Method - 2 (Recursive)
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
    ListNode* start;
    ListNode* reverseLL(ListNode* curr){
        if(curr == NULL || curr -> next == NULL){
            start = curr;
            return curr;
        }
        ListNode* temp = reverseLL(curr -> next);
        curr -> next = NULL;
        temp -> next = curr;
        return curr;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        reverseLL(head);
        return start;
    }
};

//Method - 3 (Recursive)
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
    ListNode* reverseLL(ListNode* curr){
        if(curr == NULL || curr -> next == NULL){
            return curr;
        }
        ListNode* front = curr -> next;
        ListNode* head = reverseLL(curr -> next);
        curr -> next = NULL;
        front -> next = curr;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        return reverseLL(head);
    }
};
