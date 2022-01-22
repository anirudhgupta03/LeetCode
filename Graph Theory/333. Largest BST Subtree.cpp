//https://practice.geeksforgeeks.org/problems/largest-bst/1#
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    #define ppiipii pair<pair<int,int>,pair<int,int>>
    int maxSize;
    ppiipii solve(Node* root){
        if(root == NULL){
            return {{0,1},{INT_MIN,INT_MAX}};
        }
        
        if(root -> left == NULL && root -> right == NULL){
            return {{1,1},{root -> data,root -> data}};
        }
        
        ppiipii p1 = solve(root -> left);
        ppiipii p2 = solve(root -> right);
        
        bool flag1 = p1.first.second, flag2 = p2.first.second;
        
        if(flag1 && flag2){
            int lmax = p1.second.first, rmin = p2.second.second;
            if(root -> data > lmax && root -> data < rmin){
                int data1 = rmin == INT_MAX ? root -> data : rmin;
                int data2 = lmax == INT_MIN ? root -> data : lmax;
                maxSize = max(maxSize, p1.first.first + p2.first.first + 1);
                return {{p1.first.first + p2.first.first + 1,1},{data1, data2}};
            }
        }
        return {{0,0},{-1,-1}};
    }
    int largestBst(Node *root)
    {
        if(root == NULL){
            return 0;
        }
        maxSize = 1;
        solve(root);
        return maxSize;
    }
};
