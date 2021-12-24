/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    #define pipii pair<int,pair<int,int>>	//<value,<max,min>>
    vector<int> solve(Node* root, int &maxsize){
        
        if(root == NULL){
            vector<int> v = {0,INT_MIN,INT_MAX,1};
            return v;
        }
        
        vector<int> l = solve(root -> left, maxsize);
        vector<int> r = solve(root -> right, maxsize);
        
        bool flag1 = l[3], flag2 = r[3];
        int lmax = l[1], lmin = l[2];
        int rmax = r[1], rmin = r[2];
        
        if(flag1 && flag2 && lmax < root -> data && rmin > root -> data){
            int count = l[0] + r[0] + 1;
            maxsize = max(maxsize, count);
            int tmin = (lmin == INT_MAX)? root -> data : lmin;
            int tmax = (rmax == INT_MIN)? root -> data : rmax;
            vector<int> v = {count, tmax, tmin, 1};
            return v;
        }
        else{
            int count = 1;
            maxsize = max(maxsize, count);
            int tmin = root -> data;
            int tmax = root -> data;
            vector<int> v = {count, tmax, tmin, 0};
            return v;
        }
    }
    int largestBst(Node *root)
    {
    	if(root == NULL) return 0;
        int maxsize = 1;
        
        solve(root, maxsize);
        return maxsize;
    }
};
