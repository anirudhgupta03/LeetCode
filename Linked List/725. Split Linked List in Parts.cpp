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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int n = 0;
        ListNode* temp = head;
       
        while(temp){
            n++;
            temp = temp -> next;
        }
        
        vector<int> sizes(k,n/k);
        int sum = (n/k)*(k);
        
        for(int i = 0; i < k; i++){
            if(sum != n){
                sizes[i]++;
                sum++;
            }
            else{
                break;
            }
        }
        temp = head;
        ListNode* prev = NULL;
        int ind = 0;
        vector<ListNode*> res(k);
        
        while(ind < k){
            sum = 0;
            res[ind] = temp;
            while(sum < sizes[ind]){
                sum++;
                prev = temp;
                temp = temp -> next;
            }
            ind++;
            if(prev)
            prev -> next = NULL;
        }
        return res;
    }
};
