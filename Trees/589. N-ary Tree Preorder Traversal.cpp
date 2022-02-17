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
    vector<int> res;
    vector<int> preorder(Node* root) {
        
        res.clear();
        if(root == NULL){
            return res;
        }
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            res.push_back(curr -> val);
            
            for(int i = (curr -> children).size() - 1; i >= 0; i--){
                st.push((curr -> children)[i]);
            }
        }
        return res;
    }
};
