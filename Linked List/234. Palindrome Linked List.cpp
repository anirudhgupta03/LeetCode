//Ref: https://www.youtube.com/watch?v=lRY_G-u_8jk&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=11
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
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* ptr1 = reverseLinkedList(slow), *ptr2 = head;
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1 -> val != ptr2 -> val){
                reverseLinkedList(slow);
                return false;
            }
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        reverseLinkedList(slow);
        return true;
    }
};
