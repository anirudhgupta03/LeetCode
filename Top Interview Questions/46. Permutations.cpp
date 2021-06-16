class Solution {
public:
    void solve(int ind, vector<vector<int>> &res, vector<int> &nums){
        
        if(ind == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i = ind; i < nums.size(); i++){
            swap(nums[i],nums[ind]);
            solve(ind+1,res,nums);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;

        solve(0,res,nums);
        
        return res;
    }
};
