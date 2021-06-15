//Method - 1
//Time complexity : O(L).
//The algorithm makes two traversal of the list, first to calculate list length L and second to find the (L - n) th node. There are 2L-n
//operations and time complexity is O(L).
//Space complexity : O(1).
//We only used constant extra space.
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
        
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        
        int countOfNodes = 0;
        
        while(temp){
            temp = temp -> next;
            countOfNodes++;
        }
        
        int start = countOfNodes - n + 1;
        
        if(start == 1){
            head = head -> next;
        }
        else{
            
            ListNode* prev = NULL, *curr = head;
            int tempCount = 0;
            
            while(tempCount != start - 1){
                prev = curr;
                curr = curr -> next;
                tempCount++;
            }
            
            prev -> next = curr -> next;
            curr -> next = NULL;
        }
        return head;
    }
};
