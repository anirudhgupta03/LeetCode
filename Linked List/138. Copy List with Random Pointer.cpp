//Method - 1
//TC - O(n)
//SC - O(1)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL){
            return NULL;
        }
        
        Node* temp1 = head, *temp2 = head -> next;
        
        while(temp2){
            Node* temp = new Node(temp1 -> val);
            temp1 -> next = temp;
            temp -> next = temp2;
            temp1 = temp2;
            temp2 = temp2 -> next;
        }
        Node* temp = new Node(temp1 -> val);
        temp1 -> next = temp;
        temp -> next = temp2;
        
        temp1 = head;
        
        while(temp1){
            if(temp1 -> random != NULL){
                temp1 -> next -> random = temp1 -> random -> next;
            }
            temp1 = temp1 -> next -> next;
        }
        
        Node* root;
        temp1 = head, temp2 = head -> next;
        
        root = temp1 -> next;
        
        while(temp1){
            temp1 -> next = temp2 -> next;
            temp1 = temp2 -> next;
            
            if(temp1){
                temp2 -> next = temp1 -> next;
                temp2 = temp1 -> next; 
            }
        }
        return root;
    }
};

//Method - 2
//TC - O(n)
//SC - O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* temp = head, *pre = NULL, *root = NULL;;
        
        unordered_map<Node*,Node*> umap;
        
        while(temp){
            Node* node = new Node(temp -> val);
            if(root == NULL){
                root = node;
                pre = root;
            }
            else{
                pre -> next = node;
                pre = node;
            }
            umap[temp] = node;
            temp = temp -> next;
        }
        Node* temp1 = head, *temp2 = root;
        while(temp1){
            if(temp1 -> random){
                temp2 -> random = umap[temp1 -> random];
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return root;
    }
};
