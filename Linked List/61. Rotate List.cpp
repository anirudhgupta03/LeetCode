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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp -> next;
        }
        
        k %= len;
        if(k == 0){
            return head;
        }
        
        temp = head;
        int count = 0;
        while(count != (len - k - 1)){
            temp = temp -> next;
            count++;
        }
        ListNode* t = temp -> next;
        temp -> next = NULL;
        temp = t;
        while(temp -> next){
            temp = temp -> next;
        }
        temp -> next = head;
        return t;
    }
};
