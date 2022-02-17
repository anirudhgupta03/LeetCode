/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        
        vector<int> res;
        if(root == NULL){
            return res;
        }
        stack<Node*> st1, st2;
        st1.push(root);
        
        while(!st1.empty()){
            Node* curr = st1.top();
            st1.pop();
            st2.push(curr);
            
            for(int i = 0; i < (curr -> children).size(); i++){
                st1.push((curr -> children)[i]);
            }
        }
        while(!st2.empty()){
            res.push_back(st2.top() -> val);
            st2.pop();
        }
        return res;
    }
};
