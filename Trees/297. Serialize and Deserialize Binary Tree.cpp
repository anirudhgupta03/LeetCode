//Ref: https://www.youtube.com/watch?v=T2-dVDWLQtE&t=427s
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void ser(TreeNode* root, string &s){
        
        if(root == NULL){
            s += "NULL";
            s.push_back(' ');
            return;
        }
        
        s += to_string(root -> val);
        s.push_back(' ');
        
        ser(root -> left, s);
        ser(root -> right, s);
    }
    string serialize(TreeNode* root) {
        string s;
        ser(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deser(vector<string> &v, int &ind){
        
        if(ind == v.size() || v[ind] == "NULL"){
            ind++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(v[ind]));
        ind++;
        node -> left = deser(v,ind);
        node -> right = deser(v,ind);
        
        return node;
    }
    TreeNode* deserialize(string data) {
        
        stringstream X(data);
        
        string temp;
        
        vector<string> v;
        
        while(X >> temp){
            v.push_back(temp);
        }
        int ind = 0;
        
        return deser(v,ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
