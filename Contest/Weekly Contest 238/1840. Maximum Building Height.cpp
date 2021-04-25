//Ref: https://leetcode.com/problems/maximum-building-height/discuss/1175269/C%2B%2B-with-picture-2-passes
class Solution {
public:
    int pass(vector<vector<int>>& r) {
        
        int res = 0;
        
        for (int i = 0; i < r.size() - 1; ++i) {
            
            int id1 = r[i][0], id2 = r[i+1][0];
            
            int h1 = r[i][1], h2 = r[i+1][1];
            
            int h = h1 + abs(id1 - id2);
            
            if(h > h2){
                h = (h+h2)/2;
            }
            
            res = max(res,h);
            
            r[i+1][1] = min(h,h2);
        }
        return res;
    }
    int maxBuilding(int n, vector<vector<int>>& r) {
        
        r.push_back({1,0});
        r.push_back({n,n-1});
        
        sort(r.begin(), r.end());
        
        pass(r);    //L-R
        
        reverse(begin(r), end(r));
        return pass(r); //R-L
    }
};
