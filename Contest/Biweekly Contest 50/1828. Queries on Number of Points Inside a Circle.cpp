class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            
            int xc = queries[i][0], yc = queries[i][1], rc = queries[i][2];
            
            int count = 0;
            for(int j = 0; j < points.size(); j++){
                
                int x = points[j][0], y = points[j][1];
                
                if(x*x + y*y + 2*(-xc)*x + 2*(-yc)*y + (xc*xc + yc*yc - rc*rc) <= 0){       //x^2 + y^2 + 2gx + 2fy + c <= 0           c = g^2 + f^2 - r^2
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
