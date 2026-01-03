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

//Using Level Order Traversal
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
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL) return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL) s += "N";
            else{
                s += to_string(curr -> val);
            }
            s.push_back(' ');

            if(curr){
                q.push(curr -> left);
                q.push(curr -> right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        stringstream X(data);
        string temp;
        
        vector<string> v;

        while(X >> temp){
            v.push_back(temp);
        }

        TreeNode* root = new TreeNode(stoi(v[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while(!q.empty() && i < v.size()){
            TreeNode* curr = q.front();
            q.pop();

            if(v[i] == "N"){
                curr -> left = NULL;
            }
            else{
               curr -> left = new TreeNode(stoi(v[i])); 
               q.push(curr -> left);
            }
            i++;

            if(v[i] == "N"){
                curr -> right = NULL;
            }
            else{
               curr -> right = new TreeNode(stoi(v[i])); 
               q.push(curr -> right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
