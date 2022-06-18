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

//https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103?leftPanelTab=0
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;
int largest;
vector<int> solve(TreeNode<int>* root){
    
    if(root == NULL){
        return {1,0,INT_MAX,INT_MIN};    //MIN VALUE, MAX VALUE
    }
    if(root -> left == NULL && root -> right == NULL){
        return {1,1,root -> data ,root -> data};
    }
    
    vector<int> l = solve(root -> left);
    vector<int> r = solve(root -> right);
    
    if(l[0] && r[0] && (l[3] < root -> data) && (r[2] > root -> data)){
        largest = max(largest, 1 + l[1] + r[1]);
        return {1, 1 + l[1] + r[1], min(l[2], root -> data), max(r[3], root -> data)};
    }
    else{
        return {0, 0, INT_MAX, INT_MIN};
    }
}
int largestBST(TreeNode<int>* root) 
{
    if(root == NULL){
        return 0;
    }
    largest = 1;
    solve(root);
    return largest;
}
