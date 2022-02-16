class Solution {
public:
    vector<int> pathInZigZagTree(int n) {
        
        vector<int> ans;
        int llv = 1;
        int ctval = 0;
        
        while(ctval < n){
            ctval += llv;
            llv *= 2;
        }
        llv /= 2;
        while(n != 1){
             ans.push_back(n);
             int comp = (3*llv - n - 1);
             int par = (comp/2);
             n = par;
             llv /= 2;
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
