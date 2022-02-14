//Method - 1
//Ref: https://www.youtube.com/watch?v=2Gh5WPjAgJk
//TC: O(N)
//SC: O(N)
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
class Solution {
public:
    int cam;
    unordered_set<TreeNode*> vis;
    void dfs(TreeNode* root, TreeNode* par){
        if(root == NULL){
            return;
        }
        dfs(root -> left, root);
        dfs(root -> right, root);
        
        if(par == NULL && vis.find(root) == vis.end() || vis.find(root -> left) == vis.end() || vis.find(root -> right) == vis.end()){
            cam++;
            vis.insert(root);
            vis.insert(par);
            vis.insert(root -> left);
            vis.insert(root -> right);
        }
    }
    int minCameraCover(TreeNode* root) {
        if(root == NULL) return 0;
        cam = 0;
        vis.clear();
        vis.insert(NULL);
        dfs(root, NULL);
        return cam;
    }
};

//Method - 2
//TC: O(N)
//SC: O(H)
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
class Solution {
public:
    //2 -> Has Camera
    //1 -> Covered with the camera
    //0 -> No camera is covering this node
    int cam;
    int dfs(TreeNode* root){
        if(root == NULL){
            return 1;
        }
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        
        //Check if we need to add a camera
        if(l == 0 || r == 0){
            cam++;
            return 2;
        }
        else if(l == 2 || r == 2){
            return 1;
        }
        else{
            return 0;
        }
    }
    int minCameraCover(TreeNode* root) {
        cam = 0;
        int ans = dfs(root);
        return ans == 0 ? cam + 1 : cam;
    }
};
