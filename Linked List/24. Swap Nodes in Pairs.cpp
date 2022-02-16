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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* root = NULL, *temp1 = NULL, *temp2 = head, *temp3 = head -> next;
        
        while(temp3){
            if(root == NULL){
                root = temp3;
            }
            if(temp1){
                temp1 -> next = temp3;
            }
            ListNode* temp = temp3 -> next;
            temp2 -> next = NULL;
            temp3 -> next = temp2;
            temp1 = temp2;
            temp2 = temp;
            if(temp2 == NULL){
                break;
            }
            temp3 = temp2 -> next;
            if(temp3 == NULL){
                temp1 -> next = temp2;
                break;
            }
        }
        return root;
    }
};
