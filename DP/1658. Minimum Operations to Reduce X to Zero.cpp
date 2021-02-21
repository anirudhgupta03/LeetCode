class Solution {
public:
    
    unordered_map<string,int> mem;
    
    int solve(vector<int>& nums, int x, int left, int right, int count){
        
        if(x == 0){
            return count;
        }
        
        if(left > right || x < 0){
            return 1e6;
        }
        
        string key = to_string(left) + "*" + to_string(right) + "*" + to_string(x);
        
        if(mem.count(key)){
            return mem[key];
        }
        
        int l = solve(nums,x-nums[l],left+1,right,count+1);
        int r = solve(nums,x-nums[r],left,right-1,count+1);
        
        return mem[key] = min(l,r);
    }
    int minOperations(vector<int>& nums, int x) {
        
        int ans = solve(nums,x,0,nums.size()-1,0);
        
        return ans>=1e6 ? -1 : ans;
    }
};
