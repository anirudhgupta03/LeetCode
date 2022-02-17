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
    ListNode* reverseList(ListNode* l, int &len){
        
        ListNode* temp1 = NULL, *temp2 = l, *temp3 = l -> next;
        
        while(temp3){
            len++;
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
        }
        len++;
        temp2 -> next = temp1;
        return temp2;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        int len1 = 0, len2 = 0;
        
        l1 = reverseList(l1, len1);
        l2 = reverseList(l2, len2);
        
        if(len1 > len2){
            ListNode* temp1 = l1, *temp2 = l2;
            int c = 0;
            while(temp2){
                int sum = (temp1 -> val + temp2 -> val + c);
                temp1 -> val = sum % 10;
                c = sum/10;
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            while(temp1){
                int sum = (temp1 -> val + c);
                temp1 -> val = sum % 10;
                c = sum/10;
                if(temp1 -> next == NULL && c != 0){
                    temp1 -> next = new ListNode(c);
                    break;
                }
                temp1 = temp1 -> next;
            }
            int len = 0;
            l1 = reverseList(l1,len);
            return l1;
        }
        else{
            ListNode* temp1 = l1, *temp2 = l2, *pre;
            int c = 0;
            while(temp1){
                int sum = (temp1 -> val + temp2 -> val + c);
                temp2 -> val = sum % 10;
                c = sum/10;
                temp1 = temp1 -> next;
                pre = temp2;
                temp2 = temp2 -> next;
            }
            while(temp2){
                int sum = (temp2 -> val + c);
                temp2 -> val = sum % 10;
                c = sum/10;
                pre = temp2;
                temp2 = temp2 -> next;
            }
            if(c){
                pre -> next = new ListNode(c);
            }
            int len = 0;
            l2 = reverseList(l2,len);
            return l2;
        }
        return NULL;
    }
};
