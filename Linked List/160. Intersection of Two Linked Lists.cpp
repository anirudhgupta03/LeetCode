//Ref: https://www.youtube.com/watch?v=0DYoPz2Tpt4&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=13
//Method - 1
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int len1 = 0, len2 = 0;
        
        ListNode* temp1 = headA, *temp2 = headB;
        
        while(temp1){
            len1++;
            temp1 = temp1 -> next;
        }
        
        while(temp2){
            len2++;
            temp2 = temp2 -> next;
        }
        
        temp1 = headA, temp2 = headB;
        
        if(len1 > len2){
            while(len1 != len2){
                temp1 = temp1 -> next;
                len1--;
            }
        }
        else{
             while(len1 != len2){
                temp2 = temp2 -> next;
                len2--;
            }
        }
        
        while(temp1 != temp2){
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        return temp1;
    }
};

//Method - 2
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL){
            return NULL;
        }

        ListNode* ptrA = headA, *ptrB = headB;

        while(ptrA != ptrB){

            ptrA = ptrA -> next;
            ptrB = ptrB -> next;

            if(ptrA == ptrB) return ptrA;

            if(ptrA == NULL) ptrA = headB;
            if(ptrB == NULL) ptrB = headA;
        }

        return ptrA;
    }
};
