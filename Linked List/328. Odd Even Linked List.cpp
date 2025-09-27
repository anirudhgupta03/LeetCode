//Ref: https://www.youtube.com/watch?v=qf6qp7GzD5Q&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=7

//Brute Force Solution
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
    void fetchElements(ListNode* head, vector<int> &arr){
        while(head != NULL && head -> next != NULL){
            arr.push_back(head -> val);
            head = head -> next -> next;
        }
        if(head) arr.push_back(head -> val);
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        vector<int> arr;
        fetchElements(head, arr);
        fetchElements(head -> next, arr);
        ListNode* ptr = head;
        int ind = 0;
        while(ptr != NULL){
            ptr -> val = arr[ind];
            ptr = ptr -> next;
            ind++;
        }
        return head;
    }
};

//Optimal Solution
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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL){
            return head;
        }
        ListNode* temp1 = head, *temp2 = head -> next, *prev;
        ListNode* root1 = temp1, *root2 = temp2;
        
        while(temp1 && temp2){
            
            temp1 -> next = temp2 -> next;
            prev = temp1;
            temp1 = temp2 -> next;
            
            if(temp1 != NULL){
                temp2 -> next = temp1 -> next;
                temp2 = temp1 -> next;
            }
        }
        
        if(temp1 != NULL) temp1 -> next = root2;
        else prev -> next = root2;
        return root1;
    }
};
