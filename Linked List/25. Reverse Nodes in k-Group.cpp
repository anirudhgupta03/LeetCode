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
    int lengthOfLinkedList(ListNode* head){
        int len = 0;
        ListNode* ptr = head;
        while(ptr){
            len++;
            ptr = ptr -> next;
        }
        return len;
    }
    pair<ListNode*, ListNode*> reverseLL(ListNode* start, int k){
        ListNode* prevNode = NULL, *currNode = start, *nextNode = start -> next;
        while(k > 1){
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode -> next;
            k--;
        } 
        currNode -> next = prevNode;
        return {currNode, nextNode};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = lengthOfLinkedList(head);

        ListNode* root = new ListNode(-1);
        ListNode* preGroupEnd = root, *currGroupStart = head;

        while(len >= k){
            pair<ListNode*, ListNode*> p = reverseLL(currGroupStart, k);
            
            preGroupEnd -> next = p.first;
            currGroupStart -> next = p.second;
            
            preGroupEnd = currGroupStart;
            currGroupStart = currGroupStart -> next;
            
            len -= k;
        }
        return root -> next;
    }
};
