//Ref: https://www.youtube.com/watch?v=3kMKYQ2wNIU&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=9

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
    int findLinkedListLength(ListNode* head){
        int len = 0;
        ListNode* ptr = head;
        while(ptr){
            len++;
            ptr = ptr -> next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findLinkedListLength(head);
        int nodePos = len - n;
        if(nodePos == 0) return head -> next;
        ListNode* prevNode = NULL, *currNode = head;
        while(nodePos){
            prevNode = currNode;
            currNode = currNode -> next;
            nodePos--;
        }
        prevNode -> next = currNode -> next;
        currNode -> next = NULL;
        delete currNode;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }
        if(fast == NULL) return head -> next;
        ListNode* slow = head;
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete delNode;
        return head;
    }
};
