/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    pair<Node*,Node*> solve(Node* prevnode, Node* currnode){
        
        if(currnode == NULL){
            return {NULL,NULL};
        }
        
        currnode -> prev = prevnode;
        
        if(currnode -> child && currnode -> next){
            pair<Node*,Node*> temp1 = solve(currnode, currnode -> child);
            pair<Node*,Node*> temp2 = solve(currnode, currnode -> next);
            currnode -> child = NULL;
            temp1.second -> next = temp2.first;
            temp2.first -> prev = temp1.second;
            currnode -> next = temp1.first;
            temp1.first -> prev = currnode;
            return {currnode, temp2.second};
        }
        else if(currnode -> child){
            pair<Node*,Node*> temp = solve(currnode, currnode -> child);
            currnode -> child = NULL;
            currnode -> next = temp.first;
            temp.first -> prev = currnode;
            return {currnode, temp.second};
        }
        else if(currnode -> next){
            pair<Node*,Node*> temp = solve(currnode, currnode -> next);
            currnode -> next = temp.first;
            temp.first -> prev = currnode;
            return {currnode, temp.second};
        }
        return {currnode,currnode};
    }
    Node* flatten(Node* head) {
        
        if(head == NULL){
            return NULL;
        }
        
        Node* start = head;
        solve(NULL, start);
        return start;
    }
};
