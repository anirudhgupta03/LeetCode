class Solution {
public:
    void solve(int ind, vector<int> &subset, vector<int> &nums, vector<vector<int>> &res){
        if(ind == nums.size()){
            res.push_back(subset);
            return;
        }
        solve(ind + 1, subset, nums, res);
        subset.push_back(nums[ind]);
        solve(ind + 1, subset, nums, res);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        solve(0, subset, nums, res);
        return res;
    }
};
