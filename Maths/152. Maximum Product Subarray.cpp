//Ref: https://www.youtube.com/watch?v=hnswaLJvr6g&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=28
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxprod = nums[0];
        int currmaxprod = nums[0], currminprod = nums[0], premaxprod = nums[0], preminprod = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            currmaxprod = max({premaxprod*nums[i], preminprod*nums[i], nums[i]});
            currminprod = min({premaxprod*nums[i], preminprod*nums[i], nums[i]});
            maxprod = max(maxprod, currmaxprod);
            premaxprod = currmaxprod;
            preminprod = currminprod;
        }
        return maxprod;
    }
};
