class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> v;
        
        for(int i = 0; i < (1 << n); i++)
        {
            vector<int> p;
            for(int j = 0; j < n; j++)
            {
                int k = 1 << j;
                if((i & k) != 0){
                    p.push_back(nums[j]);
                }
            }
            v.push_back(p);
        }
        
        return v;
    }
};
