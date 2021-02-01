class Solution {
public:
    
    void subset(vector<int> &nums,int ind,int n,vector<vector<int>> &v, vector<int> p){
        
        if(ind == nums.size()){
            v.push_back(p);
            return;
        }
        subset(nums,ind+1,n,v,p);
        p.push_back(nums[ind]);
        subset(nums,ind+1,n,v,p);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int ind = 0;
        vector<vector<int>> v;
        vector<int> p;
        subset(nums,ind,nums.size(),v,p);
        
        return v;
    }
};
