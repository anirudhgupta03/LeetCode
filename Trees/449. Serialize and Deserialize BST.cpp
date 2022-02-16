//Ref: https://www.youtube.com/watch?v=lP2yP8Iy88c
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
    void dfs(TreeNode* root, string &s){
        if(root == NULL){
            return;
        }
        s += to_string(root -> val);
        s.push_back(' ');
        dfs(root -> left, s);
        dfs(root -> right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s;
        dfs(root, s);
        return s;
    }
    TreeNode* constructBST(vector<string> &v, int lo, int end){
        if(lo > end) return NULL;
        TreeNode* curr = new TreeNode();
        curr -> val = stoi(v[lo]);
        int index;
        for(index = lo; index <= end; index++){
            if(stoi(v[index]) > stoi(v[lo])){
                break;
            }
        }
        curr -> left = constructBST(v, lo + 1, index - 1);
        curr -> right = constructBST(v, index, end);
        return curr;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        stringstream X(data);
        vector<string> v;
        string temp;
        while(X >> temp){
            v.push_back(temp);
        }
        return constructBST(v, 0, v.size() - 1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
