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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        
        if(root == NULL){
            return res;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            int sz = q.size();
            
            while(sz--){
                Node* curr = q.front();
                q.pop();
                
                temp.push_back(curr -> val);
                vector<Node*> v = curr -> children;
                for(int i = 0; i < v.size(); i++){
                    if(v[i]){
                        q.push(v[i]);
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
