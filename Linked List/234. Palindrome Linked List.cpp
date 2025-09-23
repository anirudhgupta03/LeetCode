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
    ListNode* reverseLinkedList(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* prevNode = NULL, *currNode = head, *nextNode = head -> next;
        while(nextNode != NULL){
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode -> next;
        } 
        currNode -> next = prevNode;
        return currNode;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return true;
        }
        ListNode* slow = head, *fast = head, *pre = NULL;
        do{
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }while(fast != NULL && fast -> next != NULL);

        pre -> next = NULL;
        ListNode* ptr1 = reverseLinkedList(slow), *ptr2 = head;
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1 -> val != ptr2 -> val){
                return false;
            }
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return true;
    }
};
