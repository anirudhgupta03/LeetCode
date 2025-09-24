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
//Time complexity : O(\max(m, n))O(max(m,n)). Assume that mm and nn represents the length of l1 and l2 respectively, the algorithm above iterates at most max(m, n) times.
//Space complexity : O(max(m,n)). The length of the new list is at most max(m,n) + 1

//Method - 1
class Solution {
public:
    
    string  solve(ListNode* root){
        string s;
        while(root){
            s.push_back(root->val+'0');
            root = root -> next;
        }
        return s;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        string s2 = solve(l2);
        string s1 = solve(l1)
        
        int n1 = s1.size(), n2 = s2.size();
        
        if(n1 > n2){
            while(n2!= n1){
                s2.push_back('0');
                n2++;
            }
        }
        else if(n2 > n1){
            while(n1!= n2){
                s1.push_back('0');
                n1++;
            }
            swap(s1,s2);
            swap(l1,l2);
        }
        
        int carry = 0;
        
        for(int i = 0; i <= n1 - 1; i++){
            int p = s1[i] - '0'+ s2[i] - '0' + carry;
            s1[i] = p%10 + '0';
            carry = p/10;
        }
        
        int i = 0;
        ListNode* temp = l1;

        while(temp -> next != NULL){
            temp -> val = s1[i] - '0';
            i++;
            temp = temp -> next;
        }
        temp -> val = s1[i] - '0';
        
        if(carry != 0){
            ListNode* root = new ListNode();
            root -> val = carry;
            temp -> next = root;
        }
        return l1;
    }
};

//Method - 2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0, sum = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        ListNode* root = new ListNode();
        ListNode* p3 = root;
        
        while(p1 != NULL || p2 != NULL){
            
            sum = carry;
            
            if(p1 != NULL){
                sum += p1 -> val;
                p1 = p1 -> next;
            }
            
            if(p2 != NULL){
                sum += p2 -> val;
                p2 = p2 -> next;
            }
            
            root -> next = new ListNode(sum%10);
            carry = sum/10;
            root = root -> next;
        }
        
        if(carry != 0){
            root -> next = new ListNode(carry);
        }
        p3 = p3 -> next;
        return p3;
    }
};

//Method - 3
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
            ptr = ptr -> next;
            len++;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(lengthOfLinkedList(l2) > lengthOfLinkedList(l1)){
            return addTwoNumbers(l2, l1);
        }
        
        ListNode *ptr1 = l1, *ptr2 = l2, *pre = NULL;
        
        int carry = 0;
        
        while(ptr1 != NULL && ptr2 != NULL){
            int sum = carry + ptr1 -> val + ptr2 -> val;
            ptr1 -> val = sum % 10;
            carry = sum/10;
            pre = ptr1;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        while(ptr1 != NULL){
            int sum = carry + ptr1 -> val;
            ptr1 -> val = sum % 10;
            carry = sum/10;
            pre = ptr1;
            ptr1 = ptr1 -> next;
        }
        
        if(carry) pre -> next = new ListNode(carry);
        
        return l1;
    }
};
