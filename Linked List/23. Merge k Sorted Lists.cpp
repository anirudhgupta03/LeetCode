//Ref: https://www.youtube.com/watch?v=1zktEppsdig&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=27
//Method - 1
//Time complexity : O(k*(k + 1)*N/2) where k is the number of linked lists.
//Space complexity : O(1)

We can merge two sorted linked list in O(1)O(1) space.
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
    ListNode* merge(ListNode* l1, ListNode* l2){
        
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        ListNode* head, *prev = NULL;
        
        while(l1 && l2){
            
            if(l1 -> val < l2 -> val){
                if(prev == NULL){
                    head = l1;
                    prev = head;
                }
                else{
                    prev -> next = l1;
                    prev = l1;
                }
                l1 = l1 -> next;
            }
            else{
                if(prev == NULL){
                    head = l2;
                    prev = head;
                }
                else{
                    prev -> next = l2;
                    prev = l2;
                }
                l2 = l2 -> next;
            }
        }
        
        if(l1){
            prev -> next = l1;
        }
        
        if(l2){
            prev -> next = l2;
        }
        
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        
        if(n == 0){
            return NULL;
        }
        if(n == 1){
            return lists[0];
        }
        
        ListNode* root = merge(lists[0],lists[1]);
        
        for(int i = 2; i < n; i++){
            root = merge(root,lists[i]);
        }
        
        return root;
    }
};

//Method - 2
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
struct cmp{
    bool operator()(ListNode* l1, ListNode* l2){
        return l1 -> val > l2 -> val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int len = lists.size();
        if(len == 0) return NULL;
        if(len == 1) return lists[0];

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(auto &x: lists){
            if(x) pq.push(x);
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            temp -> next = curr;
            temp = temp -> next;
            if(curr -> next) pq.push(curr -> next);
        }
        return dummy -> next;
    }
};
