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
        
        ListNode* temp1 = l1, *temp2 = l2;
        stack<ListNode*> st1, st2;
        
        while(temp1){
            len1++;
            st1.push(temp1);
            temp1 = temp1 -> next;
        }
        while(temp2){
            len2++;
            st2.push(temp2);
            temp2 = temp2 -> next;
        }
        
        if(len1 > len2){
            int c = 0;
            while(!st2.empty()){
                temp1 = st1.top(), temp2 = st2.top();
                st1.pop();
                st2.pop();
                int sum = (temp1 -> val + temp2 -> val + c);
                temp1 -> val = sum % 10;
                c = sum/10;
            }
            while(!st1.empty()){
                temp1 = st1.top();
                st1.pop();
                int sum = (temp1 -> val + c);
                temp1 -> val = sum % 10;
                c = sum/10;
                if(st1.size() == 0 && c != 0){
                    ListNode* root = new ListNode();
                    root -> val = c;   
                    root -> next = temp1;
                    return root;
                }
            }
            return l1;
        }
        else{
            ListNode* pre;
            int c = 0;
            while(!st1.empty()){
                temp1 = st1.top(), temp2 = st2.top();
                st1.pop();
                st2.pop();
                int sum = (temp1 -> val + temp2 -> val + c);
                temp2 -> val = sum % 10;
                c = sum/10;
                pre = temp2;
            }
            while(!st2.empty()){
                temp2 = st2.top();
                st2.pop();
                int sum = (temp2 -> val + c);
                temp2 -> val = sum % 10;
                c = sum/10;
                pre = temp2;
            }
            if(c){
                ListNode* root = new ListNode();
                root -> val = c;   
                root -> next = pre;
                return root;
            }
            return l2;
        }
        return NULL;
    }
};
