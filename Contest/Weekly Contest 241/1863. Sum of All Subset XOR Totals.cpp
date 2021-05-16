class Solution {
public:
    
    void solve(int ind, int &ans, vector<int> &nums, vector<int> &temp){
        
        if(ind == nums.size()){
            
            int sum = 0;
            
            for(int i = 0; i < temp.size(); i++){
                sum = sum ^ temp[i];
            }
            
            ans += sum;
            return;
        }
        
        solve(ind+1,ans,nums,temp);
        
        temp.push_back(nums[ind]);
        solve(ind+1,ans,nums,temp);
    }
    int subsetXORSum(vector<int>& nums) {
      
        int ans = 0;
        vector<int> temp;
        solve(0,ans,nums,temp);
        return ans;
    }
};
