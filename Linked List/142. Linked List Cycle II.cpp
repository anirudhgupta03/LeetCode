//Ref: https://www.youtube.com/watch?v=vlrxs-LPni4
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL){
            return NULL;
        }
        ListNode* slow = head, *fast = head;
        
        do{
            slow = slow -> next;
            if(fast != NULL && fast -> next != NULL){
                fast = fast -> next -> next;
            }
            else{
                return NULL;
            }
        }while(slow != fast);
        
        slow = head;
        
        //Node *prev = NULL;
        
        while(slow != fast){
            slow = slow -> next;
            //prev = fast;
            fast = fast -> next;
        }
        return slow;
    }
};
