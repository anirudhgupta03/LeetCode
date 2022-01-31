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
class FindElements {
public:
    queue<pair<TreeNode*,int>> q;
    unordered_set<int> us;
    FindElements(TreeNode* root) {
        
        while(!q.empty()) q.pop();
        
        us.clear();
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            
            TreeNode* curr = p.first;
            int val = p.second;
            
            us.insert(val);
            
            if(curr -> left){
                q.push({curr -> left, 2*val + 1});
            }
            if(curr -> right){
                q.push({curr -> right, 2*val + 2});
            }
        }
    }
    
    bool find(int target) {
        if(us.find(target) != us.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
