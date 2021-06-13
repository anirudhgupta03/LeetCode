class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int x = target[0], y = target[1], z = target[2];
        
        int a1 = 0, b1 = 0, c1 = 0;
        
        for(int i = 0; i < triplets.size(); i++){
            
            if(triplets[i][0] <= x && triplets[i][1] <= y && triplets[i][2] <= z){
                
                a1 = max(a1,triplets[i][0]);
                b1 = max(b1,triplets[i][1]);
                c1 = max(c1,triplets[i][2]);
                
                if(a1 == x && b1 == y && c1 == z){
                    return true;
                }
            }
        }
        
        return false;
    }
};
