/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* head;
    CBTInserter(TreeNode* root) {
        head = root;
    }
    
    int insert(int val) {
        
        TreeNode* temp = head;
        queue<TreeNode*> q;
        q.push(temp);
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr -> left == NULL){
                    curr -> left = new TreeNode(val);
                    return curr -> val;
                }
                else{
                    q.push(curr -> left);
                }
                
                if(curr -> right == NULL){
                    curr -> right = new TreeNode(val);
                    return curr -> val;
                }
                else{
                    q.push(curr -> right);
                }
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
